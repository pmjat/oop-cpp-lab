#include <stdio.h>
#include <math.h>
#include "triangle.h"

Triangle* new_triangle() {
	Triangle* t = (Triangle *) malloc(sizeof(Triangle) );
	t->c = t->b = t->a = 0;
	return t;	
}

Triangle* new_triangle(double a, double b, double c) {
	Triangle* t = (Triangle *) malloc(sizeof(Triangle) );
	if (!tr_resize(t, a, b, c)) {
		free(t);
		return NULL;
	}
	else
		return t;	
}

void del_triangle(Triangle* t) {
	free(t);
}

short tr_resize(Triangle *t, double a, double b, double c) {
	double s = (a+b+c)/2;
	if( a >= s || b >=s || c >=s)
		return 0;
	t->a = a;
	t->b = b;
	t->c = c;
	return 1;
}

double tr_area(Triangle *t) {
	double area;
	double s = (t->a + t->b + t->c)/2;
	if(t->a >= s || t->b >=s || t->c >=s)
		area = -1;        
	else
		area = sqrt(s*(s-t->a)*(s-t->b)*(s-t->c));
	return area;
}

double tr_perimeter(Triangle *t) {
	return t->a+t->b+t->c;
}

string tr_string(Triangle *t) {
	char buffer[50];
	sprintf(buffer, "Triangle (%6.2lf, %6.2lf, %6.2lf)\n", t->a, t->b, t->c);
	return buffer;
}

string tr_string_d(Triangle *t) {
	string trstr;
	char buffer[50];
	sprintf(buffer, "Sides (a,b,c): %6.2lf, %6.2lf, %6.2lf\n", t->a, t->b, t->c);
	trstr = trstr + buffer;
	sprintf(buffer, "Perimeter: %6.2lf\n", tr_perimeter(t));
	trstr = trstr + buffer;
	sprintf(buffer, "Area: %6.2lf\n", tr_area(t));
	trstr = trstr + buffer;
	return trstr;
}