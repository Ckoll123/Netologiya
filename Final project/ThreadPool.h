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
#include "DBcontrol.h"


class ThreadPool {
public:
    ThreadPool(unsigned int max_threads, const std::string& dbConnection, size_t recursionDepth) :
        _dbConnection(dbConnection),
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
    const std::string _dbConnection;
    size_t _recusionLimit;
};




void ThreadPool::work(){
    Indexer indexer(_recusionLimit);
    DBcontrol db(_dbConnection);

    while(true){
        auto url = _safe_queue.pop();

        {   //////////////////////////////////////////////////////////////////////////// Удалить
            std::lock_guard<std::mutex> lock(_cout_mtx); 
            std::cout << "Start thread id: " << std::this_thread::get_id() << std::endl;
            std::cout << "Working in thread id: " << std::this_thread::get_id() << ". \n";
        }   ////////////////////////////////////////////////////////////////////////////

        
        HttpsClient client;
        client.setConnectionParams(url, "443");
        client.sendGetRequest();
        indexer.indexPage(std::move(client.returnDataForIndexer()));
        indexer.sendDataToDB(db);

        while(!indexer.isAllPagesIndexed()){
            submit(indexer.getLink());
        }
    }
}

void ThreadPool::submit(Link link){
    std::cout << "Put link in queue" << std::endl;
    _safe_queue.push(std::move(link));
}
