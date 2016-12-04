#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix x(5);
    x.load(std::cin);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}