#ifndef TABLICA_ASOCJACYJNA_WZORZEC_EMPLOYEE_H
#define TABLICA_ASOCJACYJNA_WZORZEC_EMPLOYEE_H


#include <ostream>

class Employee
{
public:
    const char* name;
    const char* position;
    unsigned int age;

    Employee(const char* name, const char* position, unsigned int age);

    friend std::ostream &operator<<(std::ostream &os, const Employee &employee);
};


#endif //TABLICA_ASOCJACYJNA_WZORZEC_EMPLOYEE_H
