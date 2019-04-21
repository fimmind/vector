#pragma once

#include <initializer_list>
#include <iostream>

using namespace std;

template<class T> 
class Vector
{
public:
    Vector(int Size = 0);
    Vector(std::initializer_list<T> list);
    ~Vector();

    int size() const;

    T& operator[](int index);
    const T& operator[](int index) const;

    T* begin();
    const T* cbegin() const;
    T* end();
    const T* cend() const;
private:
    T* elem;
    int _size;
    int offset;
};


template<class T>
Vector<T>::Vector(int Size)
{
    if(Size < 0)
        throw std::out_of_range("Size cant be negative");

    _size = Size;
    offset = 0;
    elem = new T[_size];
}

template<class T> 
Vector<T>::Vector(std::initializer_list<T> list):
    Vector(list.size())
{}

template<class T>
Vector<T>::~Vector()
{
    delete elem;
}


template<class T>
int Vector<T>::size() const
{
    return _size;
}


template<class T>
T& Vector<T>::operator[](int index)
{
    if(index >= _size || index < 0)
        throw std::out_of_range("Index out of vector size");
    return elem[index];
}

template<class T>
const T& Vector<T>:: operator[](int index) const
{
    return this[index];
}



template<class T>
T* Vector<T>::begin()
{
    return &elem[0];

}
template<class T>
const T* Vector<T>::cbegin() const
{
    return begin();
}
template<class T>
T* Vector<T>::end()
{
    return begin() + _size;

}
template<class T>
const T* Vector<T>::cend() const
{
    return end();
}




template<class T> 
ostream& operator<<(ostream& os, const Vector<T>& vec)
{
    cout << "[";
    if(vec.size())
    {
        cout << vec[0];
        for(int i = 1; i < vec.size(); i++)
        {
            cout << ", " << vec[i];
        }
    }
    cout << "]";
    return os;
}
