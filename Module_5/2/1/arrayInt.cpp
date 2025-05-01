#include "arrayInt.h"

arrayInt::arrayInt(int arraySize) : 
    arr(nullptr),
    size(0),
    currentSize(0)
{
    if (arraySize > 0)
        {size = arraySize;}
    else
        throw std::invalid_argument("Размер массива должен быть больше 0");
    
    arr = new int[size];
    for (int i = 0; i < size; i++)
        {arr[i] = 0;}
}

arrayInt::~arrayInt(){
    delete[] arr;
}

void arrayInt::add_element(int data){
    if(currentSize < size){
        arr[currentSize] = data;
        currentSize++;
    }
    else
        throw std::out_of_range("Массив уже заполнен");
}

int arrayInt::get_element(int elementNumber){
    return (*this)[elementNumber - 1];
}

int arrayInt::operator[](int subscript) const{
    if (subscript < 0 || subscript >= size)
        {throw std::out_of_range("Невозможный индекс");}
    
    return arr[subscript];
}