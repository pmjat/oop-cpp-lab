# Lab02

### Exercise 1. Understand Activation record and storage allocation

Simulate execution of following program by creating and  
destroying activation records in sequence.  

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






