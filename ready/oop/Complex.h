#ifndef __COMPLEX_H_INCLUDED__
#define __COMPLEX_H_INCLUDED__

#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double real = 0, double image = 0): _real(real), _image(image) {
		cout << "Complex(double real, double image)" << endl;
	}
	// 拷贝构造函数
	Complex(Complex& source);
	Complex operator+(const Complex& source);

	double func(const Complex& x);

	// 在 class body 内定义的简单函数会自动成为 inline 函数
	double real() const { return this->_real; }
	double image() const { return this->_image; }

	~Complex();

private:
	double _real;
	double _image;
};


#endif
