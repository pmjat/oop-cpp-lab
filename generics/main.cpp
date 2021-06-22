#include <iostream>
#include <string>
#include "functions.h"
#include "triangle.h"
#include "array.h"
#include "vector.h"

using namespace std;

int main1() {

    double x=5.6, y=51.3;

    _swap<double>(x,y);

    Triangle t1(3,4,5), t2(11,13,15);

    _swap<Triangle>(t1,t2);

    cout << x << ", " << y << endl;
    cout << t1.toString() << endl;
    cout << t2.toString() << endl;

}

int main2() {

    double x=5.6, y=51.3;

    _swap(x,y);

    Triangle t1(3,4,5), t2(11,13,15);

    _swap(t1,t2);

    cout << x << ", " << y << endl;
    cout << t1.toString() << endl;
    cout << t2.toString() << endl;

}

int main3() {

    //Use sort<T> for double
    double x[10];
    int n = 0;
    x[n++] = 7.5;
    x[n++] = 6.5;
    x[n++] = 8;
    x[n++] = 5;
    x[n++] = 9;
    x[n++] = 6;
    x[n++] = 8.5;
    x[n++] = 9.5;

    sort(x, n);
    //sort<double>(x, n);
    printf("x-values sorted:\n");
    for(int i=0; i < n; i++)
        printf("%6.2lf\n", x[i]);

    //perform binary search
    int pos = binarySearch<double>(x, n, 8.5);
    if (pos >= 0 )
        printf("8.5 is found at position %d\n", pos);
    else
        printf("8.5 is not found in x-values\n");

}

int main4() {

    //Use sort<T> for string
    string friends[10];
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
    for(int i=0; i < n; i++)
        printf("%s\n", friends[i].c_str());

    //perform binary search for "RAJAT"
    int pos = binarySearch<std::string>(friends, n, "RAJAT");
    if (pos >= 0 )
        printf("RAJAT found at position %d\n", pos);
    else
        printf("RAJAT is not found in friends\n");

    return 0;

}

int main() {

    //Use sort<T> for Triangle
    Triangle x[10];

    int n = 0;
    x[n++] = Triangle(3,4,5);
    x[n++] = Triangle(13,14,15);
    x[n++] = Triangle();
    x[n++] = Triangle(10,15,20);

    sort(x, n);

    printf("Triangles Sorted on Area:\n");
    for(int i=0; i < n; i++)
        cout << x[i].toString() << endl;

    return 0;

}

int main9() {

    Array<double> a(5);
    a.setSize(2);
	a[1] = 4.6;
    a[2] = 7.2;
    //a[3] = 7.2;
    for(int i = 1; i <= a.size(); i++)
       cout << a[i] << endl;

    Array<string> names(2);
    names[1] = string("DAIICT");
    names[2] = string("Gandhinagar");

    for(int i = 1; i <= names.size(); i++)
       cout << names[i] << endl;

    return 0;

}
