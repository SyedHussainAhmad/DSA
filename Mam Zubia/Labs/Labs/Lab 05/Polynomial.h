#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<iostream>
using namespace std;
class Polynomial
{
    int* coeffs;
    int degree;
public:
    Polynomial();
    Polynomial(int d, int* arr);
    void print();
    ~Polynomial();
    Polynomial& operator = (const Polynomial& rfs);
    Polynomial(const Polynomial& rfs);
    Polynomial operator + (const Polynomial& rfs);
    Polynomial operator - (const Polynomial& rfs);
    Polynomial multiply(const Polynomial& other) const;
};


#endif // !POLYNOMIAL_H
