#include "Polynomial.h"

Polynomial::Polynomial()
{
    coeffs = nullptr;
    degree = 0;
}

Polynomial::Polynomial(int d, int* arr) :Polynomial()
{
    if (d <= 0)
    {
        return;
    }
    degree = d;
    coeffs = new int[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        coeffs[i] = arr[degree - i];
    }
}

void Polynomial::print()
{
    for (int i = 0; i < degree; i++)
    {
        int num = coeffs[degree - i];
        if (num == 0)
            num;
        else if (i != degree)
            cout << num << "x^" << degree - i << " + ";
    }
    cout << coeffs[0] << endl;
    /* for (int i = 0; i <= degree; i++)
     {
         int num = coeffs[degree - i];
         if (num == 0)
             num;
         else if (i != degree)
             cout << num << "x^" << degree - i << " + ";
         else
             cout << num << endl;
     }*/
}

Polynomial::~Polynomial()
{
    if (coeffs != nullptr)
    {
        delete[] coeffs;
        coeffs = nullptr;
        degree = 0;
    }
}

Polynomial& Polynomial::operator = (const Polynomial& rfs)
{
    if (this == &rfs)
        return *this;
    if (rfs.coeffs == nullptr)
        return *this;

    this->~Polynomial();
    degree = rfs.degree;
    coeffs = new int[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        coeffs[i] = rfs.coeffs[i];
    }
    return  *this;
}

Polynomial::Polynomial(const Polynomial& rfs)
{
    *this = rfs;
}

Polynomial Polynomial::operator + (const Polynomial& rfs)
{
    Polynomial sum{};
    Polynomial min{};
    if (degree >= rfs.degree)
    {
        sum = *this;
        min = rfs;
    }
    else
    {
        sum = rfs;
        min = *this;
    }
    for (int i = 0; (i <= degree) && (i <= rfs.degree); i++)
    {
        sum.coeffs[i] += min.coeffs[i];
    }
    return sum;
}

Polynomial Polynomial::operator - (const Polynomial& rfs)
{
    Polynomial subtract{};
    Polynomial min{};
    if (degree > rfs.degree)
    {
        subtract = *this;
        min = rfs;
    }
    else
    {
        subtract = rfs;
        min = *this;
    }
    for (int i = 0; (i <= degree) && (i <= rfs.degree); i++)
    {
        subtract.coeffs[i] -= min.coeffs[i];
    }
    return subtract;
}

void addTerm(double coeff, int exp)
{
    term[noOfTerms] = Term(coeff, exp);
    noOfTerms++;
}

Polynomial Polynomial::multiply(const Polynomial& other) const
{
    Polynomial result;

    for (int i = 0; i < term; i++)
    {
        for (int j = 0; j < other.other.term; j++)
        {
            double coefficient = term[i].coeff * other.term[i].coeff;
            int exponent = term[i].exp + other.term[i].exp;
            result.addTerm(coefficient,exponent);
        }
    }
    return result;
}
