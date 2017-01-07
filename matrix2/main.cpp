#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix x(5);
    x.load(std::cin);
    std::cout << "Hello, World!" << std::endl;
    double test = x(5, 4);
    return 0;
}