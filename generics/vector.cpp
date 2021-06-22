#include <stdexcept>
#include "vector.h"

Vector::Vector() {

    this->data = new double[10];
    this->ssize = 10;
    this->dsize = 0;

}

Vector::Vector(int size) {

    this->data = new double[size];
    this->ssize = size;
    this->dsize = 0;

}

Vector::Vector(const Vector& rhs) {

    delete[] this->data;
    //allocate storage = rhs.sszie
    this->data  = new double[rhs.ssize];

    //copy the data from rhs to this
    for(int i = 0; i < rhs.dsize; i++)
        this->data[i] = rhs.data[i];

    this->ssize = rhs.ssize;
    this->dsize = rhs.dsize;

}

void Vector::add(double x) {

    if (this->dsize == this->ssize)
        increase_size();

    this->data[this->dsize] = x;
    this->dsize++;

}

void Vector::increase_size() {

    int new_size = this->ssize+10;
    double *new_data = new double[new_size];

    for(int i = 0; i < this->dsize; i++)
        new_data[i] = this->data[i];

    delete[] this->data;

    this->data = new_data;
    this->ssize = new_size;

}

double Vector::get(int i) {

    if (i < 0 || i >= this->dsize)
        throw std::out_of_range("get: out of range!");
    return this->data[i];

}

void Vector::set(int i, double x) {

    if (i < 0 || i >= this->dsize)
        throw std::out_of_range("set: out of range!");
    this->data[i] = x;

}

double& Vector::operator[](int i) {

    if (i < 0 || i >= this->dsize)
        throw std::out_of_range("set: out of range!");
    return this->data[i];

}
const double& Vector::operator[](int i) const {

    if (i < 0 || i >= this->dsize)
        throw std::out_of_range("set: out of range!");
    return this->data[i];

}

int Vector::size(){

    return this->dsize;

}

Vector& Vector::operator=(const Vector& rhs) {

    delete[] this->data;
    //allocate storage = rhs.sszie
    this->data  = new double[rhs.ssize];

    //copy the data from rhs to this
    for(int i = 0; i < rhs.dsize; i++)
        this->data[i] = rhs.data[i];

    this->ssize = rhs.ssize;
    this->dsize = rhs.dsize;

    return *this;

}

Vector::~Vector() {

    delete[] this->data;

}

