#include <string>
using std::string;

typedef struct {
	double a;
	double b;
	double c;
} Triangle;

Triangle* new_triangle();
Triangle* new_triangle(double a, double b, double c);
void del_triangle(Triangle* t);
short tr_resize(Triangle *t, double a, double b, double c);
double tr_area(Triangle *t);
double tr_perimeter(Triangle *t);
string tr_string(Triangle *t);