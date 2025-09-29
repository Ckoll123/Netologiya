#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <future>
#include <condition_variable>
#include <utility>

#include "SafeQueue.h"
#include "Indexer.h"
#include "HttpClient.h"
#include "Link.h"



class ThreadPool {
public:
    ThreadPool(unsigned int max_threads, DBcontrol* db, size_t recursionDepth) :
        _db(db),
        _recusionLimit(recursionDepth)
    {
        for(size_t i = 0; i < std::max(1u, max_threads); i++){
            _threads.emplace_back(&ThreadPool::work, this);
        }
    }

    ~ThreadPool(){
        for(auto& element : _threads){
            element.join();
        }
    }

    void work();
    void submit(Link link);

private:
    std::vector<std::thread> _threads;
    SafeQueue<Link> _safe_queue;
    std::mutex _cout_mtx;    ////////////////////////////////
    DBcontrol* _db;
    size_t _recusionLimit;
};




void ThreadPool::work(){
    HttpClient client;
    Indexer indexer(_recusionLimit);

    while(true){
        auto url = _safe_queue.pop();

        {   //////////////////////////////////////////////////////////////////////////// Удалить
            std::lock_guard<std::mutex> lock(_cout_mtx); 
            std::cout << "Start thread id: " << std::this_thread::get_id() << std::endl;
            std::cout << "Working in thread id: " << std::this_thread::get_id() << ". " << std::endl;
        }   ////////////////////////////////////////////////////////////////////////////

        client.setConnectionParams(url, "80");
        client.sendGetRequest();
        indexer.indexPage(std::move(client.returnDataForIndexer()));
        indexer.sendDataToDB(*_db);

        while(!indexer.isAllPagesIndexed()){
            submit(indexer.getLink());
        }
    }
}

void ThreadPool::submit(Link link){
    std::cout << "Put link in queue" << std::endl;
    _safe_queue.push(std::move(link));
}
