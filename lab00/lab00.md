# Lab 00: Revisit C – structs, pointers, dynamic memory
  
Consider following triangle header file [(triangle.h)](./triangle/triangle.h) and  
implementation file [(triangle.cpp)](./triangle/triangle.cpp), and
  
### (1) execute following program

```c++
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
  
### (2) execute following program

  
```c++
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
