#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

struct Triangle {
public:
	Triangle();
    Triangle(double a, double b, double c);
    void resize(double new_a, double new_b, double new_c);
    double area();
    double perimeter();
    double getA();
    double getB();
    double getC();
    std::string toString();
private:
    double a;
    double b;
    double c;
};

#endif // TRIANGLE_H_INCLUDED
