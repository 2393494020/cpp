#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex(Complex& source)
{
	cout << "Complex(Complex& source)" << endl;
	this->_real = source._real;
	this->_image = source._image;
}

Complex Complex::operator+(const Complex& source)
{
	cout << "operator+" << endl;
	return Complex(this->_real + source._real, this->_image + source._image);
}

// 相同 class 的各个 objects 互为 friends
double Complex::func(const Complex& x)
{
	// 可以直接访问 x 的成员变量
	return x._real + x._image;
}

Complex::~Complex()
{
	cout << "~Complex" << endl;
}