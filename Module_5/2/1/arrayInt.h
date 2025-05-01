#include <iostream>
#include <stdexcept>

class arrayInt{
public:
    arrayInt(int arraySize);
    ~arrayInt();

    void add_element(int data);
    int operator[](int) const;
    int get_element(int elementNumber);

private:
    int* arr;
    int size;
    int currentSize;
};