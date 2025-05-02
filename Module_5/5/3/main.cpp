#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
public:
    MyVector() : pData(nullptr), _size(0), _capacity(0) {}
    ~MyVector() {
        delete[] pData;
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