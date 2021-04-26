#include "complex.hpp"

complex::complex(int a = 0, int b = 0) :x(a), y(b) {}
complex& complex::operator+=(const complex& f)
{
	this->x += f.x;
	this->y += f.y;
	return *this;
}
int complex::x_()
{
	return x;
}

int complex::y_()
{
	return y;
}