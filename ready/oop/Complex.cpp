#include <iostream>
#include "Complex.h"

using namespace std;

Complex::~Complex()
{
	cout << this << " ~Complex" << endl;
}

double real(const Complex& c)
{
	return c.real();
}

double image(const Complex& c)
{
	return c.image();
}

Complex Complex::operator + (const Complex& r)
{
	cout << "Complex::operator +" << endl;
	// Complex temp;
	// temp._real = _real + r._real;
	// temp._image = _image + r._image;
	// cout << "&temp:" << &temp << endl;
	// return temp;
	return Complex(_real + r._real, _image + r._image);
}

Complex::Complex(const Complex& r)
{
	cout << "Complex(const Complex& r)" << this << " copy from:" << &r << endl;
	this->_real = r._real;
	this->_image = r._image;
}

Complex& Complex::operator += (const Complex& r)
{
	return _doapl(this, r);
}

Complex operator + (const Complex& x, const Complex& y)
{
	cout << "operator +" << endl;
	return Complex(real(x) + real(y), image(x) + image(y));
}

ostream& operator << (ostream& os, const Complex& c)
{
	os << "(" << real(c) << "," << image(c) << ")";
	return os;
}

int main()
{
	Complex c1(1, 2);
	Complex c2(3, 4);
	// test operator <<
	cout << c1 << endl;
	cout << c2 << endl;

    // test operator +
	Complex c3;
	cout << "&c3:" << &c3 << endl;
	c3 = c1 + c2;
	cout << "&c3:" << &c3 << endl;
	cout << c3 << endl;

	// test operator +=
	c3 += c2;
	cout << c3 << endl;

	// test copy construct
	Complex c4(c3);
	cout << c4 << endl;
}