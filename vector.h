#pragma once

#include <initializer_list>
#include <iostream>

template<class T> 
class Vector
{
public:
    Vector(int Size = 0)
    {
        if(Size < 0)
            throw std::out_of_range("Size cant be negative");

        _size = Size;
        offset = 0;
        elem = new T[_size];
    }
    Vector(std::initializer_list<T> list):
        Vector(list.size())
    {
        
    }
    ~Vector()
    {
        delete elem;
    }

    int size() const
    {
        return _size;
    }

    T& operator[](int index)
    {
        if(index >= _size || index < 0)
            throw std::out_of_range("Index out of vector size");
        return elem[index];
    }
    const T& operator[](int index) const
    {
        return this[index];
    }
private:
    T* elem;
    int _size;
    int offset;
};
