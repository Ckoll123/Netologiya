#include <iostream>
#include <exception>


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

    T& operator=(const T& data) = delete;
    T& operator*(){
        if(_data) return *_data;
        else throw std::logic_error("Указатеь пуст!");
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
    Unique_ptr user_ptr(new int);
    *user_ptr = 2;
    std::cout << "user_ptr = " <<  *user_ptr << std::endl;

    int* raw_ptr = user_ptr.release();
    // std::cout << "user_ptr = " <<  *user_ptr;
    std::cout << "raw_ptr = " <<  *raw_ptr << std::endl;

    delete raw_ptr;
    return 0;
}