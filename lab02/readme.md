# Lab02: Appreciate few basic concepts 

### Exercise 1. Understand Stack Record of a function and storage allocation and freeing!

Simulate execution of following program by creating and  
destroying stack records (activation record) in sequence.  

```c++
#include <stdio.h>

typedef struct {
	double real;
	double imag;
} Complex;

void read_complex(Complex*);
void print_complex(Complex);
Complex add_complex(Complex c1, Complex c2);

int main() {

    Complex c1, c2, c3;

    c1.real = 1.1;
    c1.imag = 3.3;

    read_complex ( &c2 );
    c3 = add_complex(c1, c2);

    print_complex( c3 );

    return 0;

}

void read_complex(Complex* c) {

    scanf("%lf %lf", &c->real, &c->imag);

}

void print_complex(Complex c) {

    printf("%10.4lf + %10.4lfi", c.real, c.imag);

}

Complex add_complex(Complex c1, Complex c2) {

    Complex c;
    c.real = c1.real + c2.real;
    c.imag = c1.imag + c2.imag;

    return c;
}
```
### Exercise 2. Understand parameter by reference in C++

Understand following code and appreciate how do two overloaded versions of `read_complex` differ?
Also appreciate how print_complex here differs from print_complex in previous exercise.

```c++
#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

void read_complex(Complex*);
void read_complex(Complex&);
void print_complex(const Complex&);

int main() {

    Complex c1, c2;
    read_complex ( &c1 );
    read_complex ( c2 );

    print_complex( c1 );
    print_complex( c2 );

    return 0;

}

void read_complex(Complex* c) {

    scanf("%lf %lf", &c->real, &c->imag);

}

void read_complex(Complex& c) {

    scanf("%lf %lf", &c.real, &c.imag);

}

void print_complex(const Complex& c) {

    printf("%10.4lf + %10.4lfi\n", c.real, c.imag);

}
```

### Exercise 3. re-write read_book and write_book using reference parameters

Complete the following program such that it runs as expected!    

```c++
#include <stdio.h>
#include <string.h>

typedef struct {
    long isbn;
    char title[30];
    float price;
} Book;

void read_book(Book*);
void read_book(Book&);
void print_book(const Book&);

int main() {

    Book bk1, bk2;

    read_book(&bk1);
    read_book(bk2);
    print_book(bk1);
    print_book(bk2);

    return 0;
}

void read_book(Book* b) {



}

void read_book(Book& b) {



}

void print_book(const Book& b) {



}
```

### Exercise 4. Let us use `string` object of C++

In this exercise we perform following two operations on a `string array`  
1. Bubble sort. If not familiar you can understand bubble sort from here:  
https://www.geeksforgeeks.org/bubble-sort/
2. Binary Search. You can refer here for understanding binary search:  
https://www.geeksforgeeks.org/binary-search/

You are given program context in which these opeations on string array.  
You only need to implement `sort` and `binarySearch` functions.  
Test run your functions by executing the said program.

While implementing these functions, you may require learning following operations of string object  
Relational operations: http://www.cplusplus.com/reference/string/string/operators/  
`swap`: http://www.cplusplus.com/reference/string/string/swap/  
  
```c++
#include <stdio.h>
#include <string>

void sort(std::string strings[], int size);
int binarySearch(std::string strings[], int size, std::string str);

int main() {

    //Let us learn string object of c++
    std::string friends[10];
    int n = 0;
    friends[n++] = "SALIL";
    friends[n++] = "AZIZ";
    friends[n++] = "ANUBHAV";
    friends[n++] = "RAJAT";
    friends[n++] = "NISHANT";
    friends[n++] = "TANMAY";
    friends[n++] = "SMITA";
    friends[n++] = "PRAGATI";
    friends[n++] = "NIKHIL";

    sort(friends, n);
    printf("List of friends Sorted:\n");
    for(std::string s: friends)
        printf("%s\n", s.c_str());

    //perform binary search for "RAJAT"
    //note that binary search assumes that input data are sorted!
    int pos = binarySearch(friends, n, "RAJAT");
    if (pos >= 0 )
        printf("RAJAT found at position %d\n", pos);
    else
        printf("RAJAT is not found in friends\n");

    return 0;

}

void sort(std::string strings[], int size) {






}

int binarySearch(std::string strings[], int size, std::string str) {
    //Assume that input array is sorted.
    //returns pos if found else returns -1;







}
```






