#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;


class Employee {
public:
	Employee();
	Employee(string employee_name, double initial_salary);
	virtual ~Employee();
	void setSalary(double new_salary);
	virtual double getSalary() const;
	string getName() const;
private:
    string name;
    double salary;
};

#endif
