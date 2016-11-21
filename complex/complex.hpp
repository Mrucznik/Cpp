#pragma once

class Complex
{
private:
	double real;
	double imaginary;
public:
	//konstruktory
	Complex();
	Complex(double real);
	Complex::Complex(double real, double imaginary);

	//operatory
	Complex &Complex::operator=(const Complex& c);
	Complex &Complex::operator=(const double d);
	Complex &Complex::operator+=(Complex c);
	Complex &Complex::operator-=(Complex c);
	Complex &Complex::operator*=(Complex c);
	Complex &Complex::operator/=(Complex c);
	Complex Complex::operator+(const Complex& c) const;
	Complex Complex::operator-(const Complex& c) const;
	Complex Complex::operator*(const Complex& c) const;
	Complex Complex::operator/(const Complex& c) const;
	Complex Complex::operator-() const;
	bool Complex::operator==(const Complex& c) const;
	bool Complex::operator!=(const Complex& c) const;

	//metody
	double Complex::getReal() const;
	double Complex::getImaginary() const;
	double Complex::getAmplitude() const;
	double Complex::getPhase() const;
}
