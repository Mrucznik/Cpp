#include "Employee.h"

std::ostream &operator<<(std::ostream &os, const Employee &employee)
{
    os << "Employee: " << employee.name << ", position: " << employee.position << ", age: " << employee.age << "\n";
    return os;
}

Employee::Employee(const char *name, const char *position, unsigned int age) :
    name(name), position(position), age(age)
{

}
