#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>
using namespace std;

template<typename T>
class Array {
public:
    Array(int s);
    void setSize(int s);
    T& operator[](int i);
    T operator[](int i) const;
    int size();
private:
   int _size;
   T* data;
};

template<typename T>
Array<T>::Array(int s) {
    _size = s;
    data = new T[_size];
}

template<typename T>
void Array<T>::setSize(int s) {
    _size = s;
    delete [] data;
    data = new T[_size];
}

template<typename T>
T& Array<T>::operator[](int index) {
   assert((index > 0) && (index <= _size));
   return data[index-1];
}

template<typename T>
T Array<T>::operator[](int index) const {
   assert((index > 0) && (index <= _size));
   return data[index-1];
}

template<typename T>
int Array<T>::size() {
    return _size;
}

#endif
