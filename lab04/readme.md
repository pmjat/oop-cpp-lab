# Lab04: Create your own object types

Exercise 1. Complete the Complex class such that following client code works as expected!  
Separate header information in `complex.h` while put implementation in `complex.cpp`

```c++
#include <iostream>

using namespace std;

int main() {

    Complex c1(2.5,3.4), c2, c3, c;
    c2.real = 3.2;
    c2.image = 4.4;
    printf("c2:\n");
    print_complex( c2 );
    double x = c2.modulus();
    cout << "c2:modulus: " << x << endl;

    read_complex ( c3 );
    c = c1.add(c3);
    printf("c1 + c3:\n");
    print_complex( c );

    c = c2.subtract(c1); //subtracts c1 from c2
    printf("c2 - c1:\n");
    print_complex( c );

    return 0;
}
```
