# Lab03: Working with Objects

In this lab, let you yourself learn a Object type called "list" in
C++ library. This is basically a doubly linked list.
You can refer: https://www.cplusplus.com/reference/list/list/ 

Below is program that is partially done. It attempst implementing "Polygon" as abstract data type.  

You are required to implement two functions:  
1. Polygon `perimeter`. You also need to figure out how do we computer polygon perimeter.
2. `inside`; this function checks if a point is inside the polygon. You can assume that polygon is convex.  
You can use a technique given as solution 3 at http://www.eecs.umich.edu/courses/eecs380/HANDOUTS/PROJ2/InsidePoly.html
   
Note that point data used in main function are random, and I have not checked if they form a convex polygon. You should ensure that point form a convex polygon.

```c++
//source file: polygon.cpp
#include <iostream>
#include <cstring>
#include <list>

using namespace std;

struct Point {
    float x;
    float y;
};

struct Polygon {
    char name[20];
    list<Point> points;
};

void add_point(Polygon& polygon, Point p);
void print(const Polygon& polygon);
double perimeter(const Polygon&);
bool inside(Polygon& polygon, Point p);

int main() {

    Polygon polygon;
    strcpy(polygon.name, "Polygon-1");

    Point p; //instantiating Point and constructing a point object
    p.x=1.0; p.y=1.0;

    //Add first point
    add_point(polygon, p);

    //Add first point
    p.x=2.5; p.y=1.5;
    add_point(polygon, p);

    p.x=4.0; p.y=2.5;
    add_point(polygon, p);

    p.x=7.5; p.y=3.8;
    add_point(polygon, p);

    //print all points in the same sequence and separated by ","
    //and each point is printed like (4.0,2.5)
    print(polygon);
    print(polygon);

    //print polygon perimeter
    printf("%8.2f\n", perimeter(polygon));

    p.x = 1.5; p.y = 2.5;
    if (inside(polygon, p) )
        cout << "Point is inside the polygon" << endl;
    else
        cout << "Point is NOT inside the polygon" << endl;

}

void add_point(Polygon& polygon, Point p) {

    polygon.points.push_back(p);

}

void print(const Polygon& polygon) {

    printf("%s\n", polygon.name);

    for(Point p: polygon.points)
        printf("(%f,%f),", p.x, p.y);
    printf("\n");

}

double perimeter(const Polygon& polygon) {







}

bool inside(Polygon& polygon, Point p) {







}
```







