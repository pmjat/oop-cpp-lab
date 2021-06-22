#include <iostream>
using namespace std;
#include "Employee.h"

Employee::Employee()
{
   this->name = "No Name";
   this->salary = 0;
}

Employee::Employee(string name, double salary)
{
   this->name = name;
   this->salary = salary;
}

Employee::~Employee()
{
}

void Employee::setSalary(double new_salary)
{
   this->salary = new_salary;
}

double Employee::getSalary() const
{
   return this->salary;
}

string Employee::getName() const
{
   return this->name;
}
