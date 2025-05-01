#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Table
{
public:
    Table(int row, int column) : 
        _rows(row),
        _columns(column)
    {
        _pptr = new T*[row];
        for(int i = 0; i < row; ++i){
            _pptr[i] = new T[column];
        }
    }

    ~Table(){
        for(int i = 0; i < _rows; ++i) {
            delete [] _pptr[i];
        }
        delete [] _pptr;
    }

    std::pair<int, int> getSize() const{
        return std::pair<int, int>{_rows, _columns};
    }
    
    T*& operator[](int subscript){
        return _pptr[subscript];
    }

    T* operator[](int subscript) const{
        return _pptr[subscript];
    }

private:
    int _rows;
    int _columns;
    T** _pptr;
};