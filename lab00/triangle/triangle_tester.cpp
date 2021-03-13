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