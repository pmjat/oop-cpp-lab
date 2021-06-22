#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

template<typename T>
class Vector {

private:
    T *data;
    int dsize; //data size
    int ssize; //storage size
    void increase_size();

public:

    Vector();
    Vector(int size);
    Vector(const Vector& rhs); //Copy constructor
    void add(const T& x);
    T get(int i);
    void set(int i, const T& x);

    T& operator[](int i);
    const T& operator[](int i) const;

    int size();
    Vector& operator=(const Vector& rhs);
    ~Vector(); //destructor

};

template<typename T>
Vector<T>::Vector() {

    this->data = new T[10];
    this->ssize = 10;
    this->dsize = 0;

}

template<typename T>
Vector<T>::Vector(int size) {

    this->data = new T[size];
    this->ssize = size;
    this->dsize = 0;

}

template<typename T>
Vector<T>::Vector(const Vector& rhs) {

    delete[] this->data;
    //allocate storage = rhs.sszie
    this->data  = new T[rhs.ssize];

    //copy the data from rhs to this
    for(int i = 0; i < rhs.dsize; i++)
        this->data[i] = rhs.data[i];
        //ASSERTion: T overloads operator= if deep copy is required

    this->ssize = rhs.ssize;
    this->dsize = rhs.dsize;

}

template<typename T>
void Vector<T>::add(const T& x) {

    if (this->dsize == this->ssize)
        increase_size();

    this->data[this->dsize] = x;
    //ASSERTion: T overloads operator= if deep copy is required
    this->dsize++;

}

template<typename T>
void Vector<T>::increase_size() {

    int new_size = this->ssize+10;
    T *new_data = new T[new_size];

    for(int i = 0; i < this->dsize; i++)
        new_data[i] = this->data[i];
        //ASSERTion: T overloads operator= if deep copy is required

    delete[] this->data;

    this->data = new_data;
    this->ssize = new_size;

}

template<typename T>
T Vector<T>::get(int i) {

    if (i < 0 || i >= this->dsize)
        throw std::out_of_range("get: out of range!");
    return this->data[i];

}

template<typename T>
void Vector<T>::set(int i, const T& x) {

    if (i < 0 || i >= this->dsize)
        throw std::out_of_range("set: out of range!");
    this->data[i] = x;
    //ASSERTion: T overloads operator= if deep copy is required

}

template<typename T>
T& Vector<T>::operator[](int i) {

    if (i < 0 || i >= this->dsize)
        throw std::out_of_range("set: out of range!");
    return this->data[i];

}

template<typename T>
const T& Vector<T>::operator[](int i) const {

    if (i < 0 || i >= this->dsize)
        throw std::out_of_range("set: out of range!");
    return this->data[i];

}

template<typename T>
int Vector<T>::size(){

    return this->dsize;

}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs) {

    delete[] this->data;
    //allocate storage = rhs.sszie
    this->data  = new T[rhs.ssize];

    //copy the data from rhs to this
    for(int i = 0; i < rhs.dsize; i++)
        this->data[i] = rhs.data[i];
        //ASSERTion: T overloads operator= if deep copy is required

    this->ssize = rhs.ssize;
    this->dsize = rhs.dsize;

    return *this;

}

template<typename T>
Vector<T>::~Vector() {

    delete[] this->data;

}

#endif // VECTOR_H_INCLUDED
