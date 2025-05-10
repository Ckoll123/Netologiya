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

    class ColumnProxy {
    public:
        ColumnProxy(T* p_row, int columns) : _p_row(p_row), _columns(columns) {}
        T& operator[](size_t subscript) {
            if ((subscript < 0) || (subscript >= _columns)){
                throw std::out_of_range("Невозможный индекс столбца");
            }
            return _p_row[subscript];
        }
    private:
        T* _p_row;
        const int& _columns;
    };
    
    ColumnProxy operator[](int subscript){
        if ((subscript < 0) || (subscript >= _rows)){
            throw std::out_of_range("Невозможный индекс строки");
        }
        return ColumnProxy(_pptr[subscript], _columns);
    }

    ColumnProxy operator[](int subscript) const{
        if ((subscript < 0) || (subscript >= _rows)){
            throw std::out_of_range("Невозможный индекс строки");
        }
        return ColumnProxy(_pptr[subscript], _columns);
    }

    Table(const Table&) = delete;
	Table& operator= (const Table&) = delete;
    
private:
    int _rows;
    int _columns;
    T** _pptr;
};