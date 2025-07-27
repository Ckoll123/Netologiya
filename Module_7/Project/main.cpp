#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <future>
#include <condition_variable>

using namespace std;

mutex cout_mtx;

void func1(){
    lock_guard<mutex> lk_g(cout_mtx);
    cout << "Working in thread id: " << this_thread::get_id() << ". ";
    cout << __FUNCTION__ << endl;
}

void func2(){
    lock_guard<mutex> lk_g(cout_mtx);
    cout << "Working in thread id: " << this_thread::get_id() << ". ";
    cout << __FUNCTION__ << endl;
}

void func3(){
    lock_guard<mutex> lk_g(cout_mtx);
    cout << "Working in thread id: " << this_thread::get_id() << ". ";
    cout << __FUNCTION__ << endl;
}

void func4(){
    lock_guard<mutex> lk_g(cout_mtx);
    cout << "Working in thread id: " << this_thread::get_id() << ". ";
    cout << __FUNCTION__ << endl;
}

void func5(){
    lock_guard<mutex> lk_g(cout_mtx);
    cout << "Working in thread id: " << this_thread::get_id() << ". ";
    cout << __FUNCTION__ << endl;
}


template <typename T>
class Safe_queue {
public:
    void push(T value);
    void pop();
    bool empty(){ return q.empty(); };
    
    condition_variable cond_var;
    mutex mtx;

private:
    T front();

    queue<T> q;
};

template <typename T>
void Safe_queue<T>::push(T value){
    lock_guard<mutex> lock_g(mtx);
    q.push(move(value));
    cond_var.notify_all();
};

// template <typename T>
// void Safe_queue<T>::pop(){
//     lock_guard<mutex> lock_g(mtx);
//     q.pop();
// }

// template <typename T>
// T Safe_queue<T>::front(){
//     unique_lock<mutex> un_l(mtx);
//     cond_var.wait(un_l, [this]() { return !q.empty(); });
//     cout << "Start thread id: " << this_thread::get_id() << endl;
//     T value = move(q.front());
//     return value;
// }

template <typename T>
void Safe_queue<T>::pop(){
    unique_lock<mutex> un_l(mtx);
    cond_var.wait(un_l, [this]() { return !q.empty(); });
    packaged_task<void()> task = front();
    q.pop();
    task();
}

template <typename T>
T Safe_queue<T>::front(){
    cout << "Start thread id: " << this_thread::get_id() << endl;
    T value = move(q.front());
    return value;
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
        // packaged_task<void()> task = safe_queue.front();
        safe_queue.pop();
        // task();
    }
}

void Thread_pool::submit(packaged_task<void()> task){
    unique_lock<mutex> un_l(safe_queue.mtx);
    cout << "Put task in queue" << endl;
    un_l.unlock();

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