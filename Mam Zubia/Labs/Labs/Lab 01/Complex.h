#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
using namespace std;

class Complex
{
	double real;
	double imag;
public:
	Complex();
	Complex(double,double);
	double getReal() const;
	double getImag() const;
	void setReal(double);
	void setImag(double);
	Complex add(const Complex& c);
	Complex subtract(const Complex& c);
	Complex multiply(const Complex& c);
	Complex divide(const Complex& c);
	Complex conjugate();
	void display();
};

#endif // !COMPLEX_H
