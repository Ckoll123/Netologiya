#include <iostream>
#include <exception>

struct Person {
    std::string name;
    int age;
    void greet() { std::cout << "Hello, " << name << "!\n"; }
};

template <typename T>
class Unique_ptr{
public:
    Unique_ptr(T* data = nullptr) : _data(data) {};
    Unique_ptr(const Unique_ptr& ptr) = delete;
    ~Unique_ptr(){
        if (_data){
            delete _data;
        }
    }

    Unique_ptr& operator=(const Unique_ptr& data) = delete;
    T& operator*(){
        if(_data) return *_data;
        else throw std::logic_error("Указатель пуст!");
    }

    T* operator->(){
        if(_data) return _data;
        else throw std::logic_error("Указатель пуст!");
    }

    T* release(){
        T* temp_data = _data;
        _data = nullptr;
        return temp_data;
    }

private:
    T* _data;
};


int main(){
    Unique_ptr user_ptr2(new Person{"Alice", 30});

    Unique_ptr user_ptr(new int);
    *user_ptr = 2;
    std::cout << "user_ptr = " <<  *user_ptr << std::endl;

    int* raw_ptr = user_ptr.release();
    // std::cout << "user_ptr = " <<  *user_ptr;
    std::cout << "raw_ptr = " <<  *raw_ptr << std::endl;
    
    delete raw_ptr;
    return 0;
}