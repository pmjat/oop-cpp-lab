#include <iostream>
#include <string>
#include "vector.h"
#include "triangle.h"

using namespace std;

int main() {

    Vector<Triangle> x(3);
    x.add( Triangle(3,4,5) );
    x.add( Triangle(13,14,15) );
    x.add( Triangle() );
    x.add( Triangle(10,15,20) );

    Vector<Triangle> y, z;
    z = y = x;

    z[2] = Triangle(100,150,200);

    y.add(Triangle(50,60,70));

    cout << "x: " << x.size() << endl;
    for(int i=0; i < x.size(); i++)
        cout << x[i].toString() << endl;

    cout << "y: " << y.size() << endl;
    for(int i=0; i < y.size(); i++)
        cout << y.get(i).toString() << endl;

    cout << "z: " << z.size() << endl;
    for(int i=0; i < z.size(); i++)
        cout << z[i].toString() << endl;

}

int main1() {

    Vector<double> x(3);
    x.add(7.4);
    x.add(4.2);
    x.add(6.5);
    x.add(8);
    x.add(7.5);
    x.add(8.3);

    Vector<double> y, z;
    z = y = x;

    z[3] = 99.9;

    y.add(12.22);
    y.add(13.33);

    cout << "x: " << x.size() << endl;
    for(int i=0; i < x.size(); i++)
        cout << x.get(i) << endl;

    cout << "y: " << y.size() << endl;
    for(int i=0; i < y.size(); i++)
        cout << y[i] << endl;

    cout << "z: " << z.size() << endl;
    for(int i=0; i < z.size(); i++)
        cout << z[i] << endl;

}

