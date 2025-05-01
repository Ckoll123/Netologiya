#include <iostream>
#include <stdexcept>

class ArrayInt{
public:
    ArrayInt(int arraySize);
    ~ArrayInt();

    void add_element(int data);
    int operator[](int) const;
    int get_element(int elementNumber);

    const ArrayInt& operator=(const ArrayInt&);

private:
    int* arr;
    int size;
    int currentSize;
};