# Lab 00: Revisit C – structs, pointers, dynamic memory
  
In this lab you are given code that implement following abstractions  
1. Triangle ([triangle.h](./triangle/triangle.h) and [triangle.cpp](./triangle/triangle.cpp))
1. Bank Account ([bankaccount.h](./bank/bankaccount.h), [bankaccount.cpp](./triangle/bankaccount.cpp))
1. Bank Branch ([branch.h](.bank/branch.h), [branch.cpp](./bank/branch.cpp))

Objective of the lab is to appreciate concepts of:
* abstraction implementation through structs, and
* dynamic memory allocation

### Exercise (1) execute following triangle tester 

> Executing this program requires adding `trainagle.h` and `triangle.cpp` to your project.

```c++ 
//file name: triangle_tester.cpp
#include <stdio.h>
#include "triangle.h"

int main(int argc, char **argv) {

    Triangle* t = new_triangle();
    double a, b, c;
    printf("Enter three sides for a triangle\n"); 
    scanf("%lf %lf %lf",&a, &b, &c);
    printf("Inputs: %6.2lf %6.2lf %6.2lf\n", a, b, c);
    if (tr_resize(t, a, b, c)) {
        printf("Perimeter: %10.2lf\n", tr_perimeter(t));
        printf("Area: %10.2lf\n", tr_area(t));		
    }
    else
        printf("Invalid values inputted for a triangle!!");
    del_triangle(t);

    return 0;
}
```
  
### Exercise (2) execute following tester program that uses array of triangles

> Executing this program requires adding `trainagle.h` and `triangle.cpp` to your project.

```c++
//file name: triangle_array.cpp
#include <stdio.h>
#include "triangle.h"

int main(int argc, char **argv) {

    int n = 3;

    Triangle* ta[n];
    ta[0] = new_triangle(3,4,5);
    ta[1] = new_triangle(10,8,20);
    ta[2] = new_triangle(5.5,4.2,4.8);

    double total_area = 0;
    for(int i = 0; i < 3; i++)
        if (ta[i] != NULL) {
            total_area += tr_area( ta[i] );
            printf("%s", tr_string(ta[i]).c_str());		
        }
        else
            printf("Invalid Triangle\n");		

    printf("Total Area: %8.2lf\n", total_area);		

    //free storage
    for(int i = 0; i < 3; i++)
        del_triangle(ta[i]);

    return 0;
}
```
  
### Exercise (3) execute following bank account tester

> Executing this program requires adding `bankaccount.h` and `bankaccount.cpp` to your project.


```c++
//file name: bankaccount_tester.cpp
#include <stdio.h>
#include <string.h>
#include "bankaccount.h"

int main(int argc, char **argv) {

	BankAccount* ba1 = new_account();
	strcpy(ba1->customer, "Sunil");
	printf("Account-1: %s\n", ba_string(ba1).c_str());
	BankAccount* ba2 = new_account("Pankaj", 5000);

	deposit(ba1, 3000);
	withdraw(ba2, 1000);

	printf("Account-1: %s\n", ba_string(ba1).c_str());
	printf("Account-2: %s\n", ba_string(ba2).c_str());
	
	del_account(ba1);
	del_account(ba2);

	return 0;
}
```

### Exercise (4) execute following branch tester

> Executing this program requires adding `bankaccount.h`,`bankaccount.cpp`,  
>  `branch.h` and `branch.cpp` to your project.

```c++
//file name: branch_tester.cpp
#include <stdio.h>
#include <string.h>
#include <string>
#include "branch.h"

extern short NACC;
extern BankAccount* accounts[];

int main(int argc, char **argv) {
	
	init_branch();

	open_account("Sanjay", 10000);
	open_account("Pankaj", 1000);
	open_account("Arnav", 5000);
	open_account("Sanjay", 3000);

	BankAccount* acc;
	//List All accounts
	for (int i=0; i < NACC; i++ ) {
		acc = accounts[i];
		if (acc != NULL)
			printf("Account: %s\n", ba_string(acc).c_str());		
	} 

	//Now suppose you want to depsoit 3000 to 
	//   accno 1003.
	acc = find_account( 1003 );
	deposit(acc, 3000);
	//Show new balance of the account
	printf("Account: %s\n", ba_string(acc).c_str());
	
	//1001
	acc = find_account( 1001 );
	withdraw(acc, 3000);	
	printf("Account: %s\n", ba_string(acc).c_str());

	//1002
	close_account( 1002 );
	acc = find_account( 1002 );
	if (acc == NULL)
		printf("Account 1002 Closed\n");
	else
		printf("Account: %s\n", ba_string(acc).c_str());
	
	//List All accounts
	for (int i=0; i < NACC; i++ ) {
		acc = accounts[i];
		if (acc != NULL)
			printf("Account: %s\n", ba_string(acc).c_str());		
	} 

	close_branch();
	
	return 0;

}
```
