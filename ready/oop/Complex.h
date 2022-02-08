#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>
using namespace std;

// 成员变量不带指针的复数类
class Complex
{
public:
	Complex(double real = 0, double image = 0): _real(real), _image(image) {
		cout << "Complex(double real, double image)" << endl;
	}

	Complex& operator += (const Complex& r);

	// 在 class body 内定义的简单函数会自动成为 inline 函数
	double real() const { return this->_real; }
	double image() const { return this->_image; }

	~Complex();

private:
	double _real;
	double _image;
	friend Complex& _doapl(Complex* ths, const Complex& target)
	{
		// 相同类型的不同对象互为友元
		ths->_real += target._real;
		ths->_image += target._image;
		return *ths;
	}
};


#endif
