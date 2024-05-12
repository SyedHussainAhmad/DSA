//#include"Complex.h"
//
//Complex::Complex()
//{
//	real = 0;
//	imag = 0;
//}
//
//Complex::Complex(double x, double y)
//{
//	real = x;
//	imag = y;
//}
//
//double Complex::getReal() const
//{
//	return real;
//}
//
//double Complex::getImag() const
//{
//	return imag;
//}
//
//void Complex::setReal(double x)
//{
//	real = x;
//}
//
//void Complex::setImag(double y)
//{
//	imag = y;
//}
//
//Complex Complex::add(const Complex& c)
//{
//	Complex result;
//	result.setReal((real + c.getReal()));
//	result.setImag((imag + c.getImag()));
//	return result;
//}
//
//Complex Complex::subtract(const Complex& c)
//{
//	Complex result;
//	result.setReal((real - c.getReal()));
//	result.setImag((imag - c.getImag()));
//	return result;
//}
//
//Complex Complex::multiply(const Complex& c)
//{
//	Complex result;
//	result.setReal(((real * c.getImag()) - (c.getReal() * imag)));
//	result.setImag(((real * c.getReal()) + (imag * c.getImag())));
//	return result;
//}
//
//Complex Complex::divide(const Complex& c)
//{
//	Complex result;
//	double denominator = (c.getReal() * c.getReal()) - (c.getImag() * c.getImag());
//	double realNominator = ((real * c.getImag()) + (c.getReal() * imag));
//	double imagNominator = ((imag * c.getImag()) - (real * c.getReal()));
//
//	result.setReal(realNominator/denominator);
//	result.setImag(imagNominator/denominator);
//	return result;
//}
//
//Complex Complex::conjugate()
//{
//	Complex result;
//	result.setReal(real);
//	result.setImag((imag*-1));
//	return result;
//}
//
//void Complex::display()
//{
//	char ch = imag < 0 ? '-' : '+';
//	cout << real << ch << imag << "i";
//}
