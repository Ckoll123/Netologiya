#include <iostream>
#include <vector>
#include <queue>
// #include <thread>
#include <condition_variable>



template <typename T>
class SafeQueue {
public:
    void push(T value);
    T pop();
    bool empty(){ return q.empty(); };
    
public:
    std::mutex mtx;

private:
    std::queue<T> q;
    std::condition_variable condVar;
};

template <typename T>
void SafeQueue<T>::push(T value){
    std::lock_guard<std::mutex> lock_g(mtx);
    q.push(std::move(value));
    condVar.notify_all();
};

template <typename T>
T SafeQueue<T>::pop(){
    std::cout << "Waiting for new link in queue... (thread " << std::this_thread::get_id() << ")\n";
    std::unique_lock<std::mutex> uniqueLock(mtx);
    condVar.wait(uniqueLock, [this]() { return !q.empty(); });
    T task = std::move(q.front());
    q.pop();
    uniqueLock.unlock();

    return task;
}