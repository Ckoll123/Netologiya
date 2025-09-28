#include <iostream>
#include <set>
#include <mutex>


template <typename T>
class SafeSet {
public:
    void insert(const T& element);
    bool find(const T& element);
    
private:
    std::mutex mtx;
    std::set<T> s;
};

template <typename T>
void SafeSet<T>::insert(const T& element){
    std::lock_guard<std::mutex> lock_g(mtx);
    s.insert(element);
};

template <typename T>
bool SafeSet<T>::find(const T& element){   
    std::lock_guard<std::mutex> lock_g(mtx);
    return s.find(element) != s.end();
}