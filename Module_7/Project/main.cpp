#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <future>
#include <condition_variable>

using namespace std;

mutex cout_mtx;

void func1(){
    cout << __FUNCTION__ << endl;
}

void func2(){
    cout << __FUNCTION__ << endl;
}

void func3(){
    cout << __FUNCTION__ << endl;
}

void func4(){
    cout << __FUNCTION__ << endl;
}

void func5(){
    cout << __FUNCTION__ << endl;
}


template <typename T>
class Safe_queue {
public:
    void push(T value);
    T pop();
    bool empty(){ return q.empty(); };
    
    
    mutex mtx;
private:
    queue<T> q;
    condition_variable cond_var;
};

template <typename T>
void Safe_queue<T>::push(T value){
    lock_guard<mutex> lock_g(mtx);
    q.push(move(value));
    cond_var.notify_all();
};

template <typename T>
T Safe_queue<T>::pop(){
    unique_lock<mutex> un_l(mtx);
    cond_var.wait(un_l, [this]() { return !q.empty(); });
    T task = move(q.front());
    q.pop();
    un_l.unlock();

    return task;
}


class Thread_pool {
public:
    Thread_pool(unsigned int max_threads)
    {
        for(size_t i = 0; i < max(1u, max_threads); i++){
            threads.emplace_back(&Thread_pool::work, this);
        }
    }

    ~Thread_pool(){
        for(auto& element : threads){
            element.join();
        }
    }

    void work();
    void submit(packaged_task<void()> task);

private:
    vector<thread> threads;
    Safe_queue<packaged_task<void()>> safe_queue;
};

void Thread_pool::work(){
    while(true){
        auto task = safe_queue.pop();

        {
            lock_guard<mutex> lock(cout_mtx);
            cout << "Start thread id: " << this_thread::get_id() << endl;
            cout << "Working in thread id: " << this_thread::get_id() << ". " << endl;
        }

        task();
    }
}

void Thread_pool::submit(packaged_task<void()> task){
    cout << "Put task in queue" << endl;
    safe_queue.push(move(task));
}




int main(){
    Thread_pool thread_pool(thread::hardware_concurrency() - 1);

    while (true){
        this_thread::sleep_for(2s);
        thread_pool.submit(packaged_task<void()>(func1)); 
        thread_pool.submit(packaged_task<void()>(func2));
        thread_pool.submit(packaged_task<void()>(func3));
        thread_pool.submit(packaged_task<void()>(func4));
        thread_pool.submit(packaged_task<void()>(func5));
    }

    return 0;
}