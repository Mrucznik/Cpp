#include <cmath>
#include "complex.hpp"

Complex::Complex()
{
}

Complex::Complex(double real) :
        real(real)
{
}

Complex::Complex(double real, double imaginary) :
        real(real), imaginary(imaginary)
{
}

Complex &Complex::operator=(const Complex& c)
{
    real = c.real;
    imaginary = c.imaginary;
    return *this;
}

Complex &Complex::operator=(const double d)
{
    real = d;
    imaginary = 0;
    return *this;
}

Complex &Complex::operator+=(Complex c)
{
    real += c.real;
    imaginary += c.imaginary;
    return *this;
}

Complex &Complex::operator-=(Complex c)
{
    real -= c.real;
    imaginary -= c.imaginary;
    return *this;
}

Complex &Complex::operator*=(Complex c)
{
    real = real*c.real - imaginary*c.imaginary;
    imaginary = imaginary*c.real - real*c.imaginary;
    return *this;
}

Complex &Complex::operator/=(Complex c)
{
    double divisor = imaginary*imaginary + c.imaginary*c.imaginary;
    real = (real*c.real + imaginary*c.imaginary)/divisor;
    imaginary = (imaginary*c.real + real*c.imaginary)/divisor;
    return *this;
}

Complex Complex::operator-() const
{
    return Complex(-real, -imaginary);
}

bool Complex::operator==(const Complex& c) const
{
    return real == c.real && imaginary == c.imaginary;
}

bool Complex::operator!=(const Complex& c) const
{
    return !(c == *this);
}

double Complex::getReal() const
{
    return real;
}

double Complex::getImaginary() const
{
    return imaginary;
}

double Complex::getAmplitude() const
{
    return sqrt(real*real + imaginary*imaginary);
}

double Complex::getPhase() const
{
    return atan2(imaginary, real);
}
