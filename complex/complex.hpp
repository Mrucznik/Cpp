#pragma once

#include <iostream>

class Complex
{
private:
	double real;
	double imaginary;
public:
	//konstruktory
	Complex();
	Complex(double real);
	Complex(double real, double imaginary);

	//operatory
	Complex& operator=(const Complex& c);
	Complex& operator=(const double d);
	Complex& operator+=(Complex c);
	Complex& operator-=(Complex c);
	Complex& operator*=(Complex c);
	Complex& operator/=(Complex c);
	Complex operator-() const;
	bool operator==(const Complex& c) const;
	bool operator!=(const Complex& c) const;
	
	//friendy
	friend Complex operator+(Complex c1, Complex c2);
	friend Complex operator-(Complex c1, Complex c2);
	friend Complex operator*(Complex c1, Complex c2);
	friend Complex operator/(Complex c1, Complex c2);
	
	friend std::ostream& operator<< (std::ostream& s, const Complex & c)
	{
		s << "(" << c.real << "," << c.imaginary << ")";
		return s;
	}

	//metody
	double getReal() const;
	double getImaginary() const;
	double getAmplitude() const;
	double getPhase() const;
};

inline Complex operator+(Complex c1, Complex c2)
{
    return Complex(c1.real+c2.real, c1.imaginary+c2.imaginary);
}

inline Complex operator-(Complex c1, Complex c2)
{
    return Complex(c1.real-c2.real, c1.imaginary-c2.imaginary);
}

inline Complex operator*(Complex c1, Complex c2)
{
    return Complex(c1.real*c2.real - c1.imaginary*c2.imaginary, c1.imaginary*c2.real - c1.real*c2.imaginary);
}

inline Complex operator/(Complex c1, Complex c2)
{
    double divisor = c1.imaginary*c1.imaginary + c2.imaginary*c2.imaginary;
    return Complex((c1.real*c2.real + c1.imaginary*c2.imaginary)/divisor, (c1.imaginary*c2.real + c1.real*c2.imaginary)/divisor);
}

