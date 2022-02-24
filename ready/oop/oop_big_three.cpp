#include <iostream>

using namespace std;

class T
{
public:
	T();
	
	// copy constructor
	T(const T& source);
	
	// copy assignment operator
	T& operator = (const T& source);

	// destructor
	~T();
};

T::T()
{
	cout << this << " construct" << endl;
}

T::T(const T& source)
{
	cout << this << " copy from " << &source << endl;
}

T& T::operator = (const T& source)
{
	cout << this << " assign from " << &source << endl;
	if (this != &source)
	{
		// do something
	}
	return *this;
}

T::~T()
{
	cout << this << " destruct" << endl;
}

T foo()
{
	// ms visual studio 平台下返回临时对象会走两个步骤
	// 1. 构造函数
	// 2. 拷贝构造函数
	// T t;
	// return t;
	// 返回匿名对象走一个步骤
	// 1. 构造函数
	return T();
}

int main()
{
	T ta;      // 调用构造函数
	T tb(ta);  // 调用拷贝构造函数
	T tc = ta; // 调用拷贝构造函数
	tc = tb;   // 调用拷贝赋值运算符 =
	foo();
	return 0;
}