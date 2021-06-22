#include <string>
#include <cmath>
#include <stdexcept>
#include "Triangle.h"

using namespace std;

Triangle::Triangle() {
	this->resize(0,0,0);
}
Triangle::Triangle(double a, double b, double c) {
	this->resize(a,b,c);
}

void Triangle::resize(double new_a, double new_b, double new_c) {
	double s = (new_a + new_b + new_c )/2.0;
	if ( new_a > s || new_b > s || new_c > s )
		throw logic_error("Invalid Arguments for forming the triangle");
	this->a = new_a;
	this->b = new_b;
	this->c = new_c;
}

double Triangle::area() {
	double area, s;
	s = (a+b+c)/2;
	area = sqrt(s *(s-a) * (s-b) * (s-c));
	return area;
}

double Triangle::perimeter() {
	double p;
	p = a+b+c;
	return p;
}

double Triangle::getA(){
	return a;
}

double Triangle::getB(){
	return b;
}

double Triangle::getC(){
	return c;
}

string Triangle::toString() {
	char str[50];
	sprintf(str, "Triangle: {A:%6.2lf, B:%6.2lf, C:%6.2lf}", this->a, this->b, this->c);
	return str;
}
