#include <iostream>
#include <vector>
#include <queue>
#include <thread>
// #include <future>
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
    q.push(move(value));
    condVar.notify_all();
};

template <typename T>
T SafeQueue<T>::pop(){
    std::unique_lock<std::mutex> uniqueLock(mtx);
    condVar.wait(uniqueLock, [this]() { return !q.empty(); });
    T task = move(q.front());
    q.pop();
    uniqueLock.unlock();

    return task;
}