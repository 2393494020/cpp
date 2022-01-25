#include <iostream>
#include <string>
#include "Complex.h"
#include "Fraction.h"

using namespace std;

int main()
{
	cout << "复数" << endl;	
	{
		Complex ca;
		Complex cb(1, 2);
		Complex cc = ca + cb;

		cout << cc.real() << endl;
		cout << cc.image() << endl;
		cout << &cc << endl;
	}

	cout << "分数" << endl;
	{
		Fraction f1(4, 5);
		double d = 5 + f1; // f 转换为 double
		Fraction f2 = f1 + 3;
	}
	return 0;
}