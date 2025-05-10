#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
public:
    MyVector() : pData(nullptr), _size(0), _capacity(0) {}
    
    MyVector(const MyVector& copy) :
        _size(copy.size()),
        _capacity(copy.size())
    {
        arr = new int[_capacity];
        for (int i = 0; i < _size; i++)
            {arr[i] = copy.at(i);}
    }

    ~MyVector() {
        delete[] pData;
    }

    const MyVector& operator=(const MyVector& right){
        if (&right != this){
            if(_capacity != right.capacity()){
                delete[] arr;
                _capacity = right.capacity();
                arr = new int[_capacity];
            }
    
            _size = right.size();
            for (int i = 0; i < _size; i++)
                {arr[i] = right.at(i);}
        }
    
        return *this;
    }

    int size() const {
        return _size;
    }

    int capacity() const {
        return _capacity;
    }

    T& at(int index) {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Невозможный индекс");
        }
        return pData[index];
    }

    void push_back(const T& value) {
        if (_size == _capacity) {
            int newCapacity = (_capacity == 0) ? 1 : _capacity * 2;
            T* newData = new T[newCapacity];
            for (int i = 0; i < _size; ++i) {
                newData[i] = pData[i];
            }
            delete[] pData;
            pData = newData;
            _capacity = newCapacity;
        }
        pData[_size++] = value;
    }
    
private:
    T* pData;
    int _size;
    int _capacity;
};