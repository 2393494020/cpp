#include "complex.hpp"

complex::complex(int a = 0, int b = 0) :x(a), y(b) {}
complex& complex::operator += (const complex& c)
{
	this->x += c.x;
	this->y += c.y;
	return *this;
}
int complex::x_() const
{
	return x;
}

int complex::y_() const
{
	return y;
}
