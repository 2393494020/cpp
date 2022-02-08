#include <iostream>
#include "Complex.h"

using namespace std;

Complex::~Complex()
{
	cout << "~Complex" << endl;
}

double real(const Complex& c)
{
	return c.real();
}

double image(const Complex& c)
{
	return c.image();
}

Complex& Complex::operator += (const Complex& r)
{
	return _doapl(this, r);
}

Complex operator + (const Complex& x, const Complex& y)
{
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
	Complex c3 = c1 + c2;
	cout << c3 << endl;

	// test operator +=
	c3 += c2;
	cout << c3 << endl;
}