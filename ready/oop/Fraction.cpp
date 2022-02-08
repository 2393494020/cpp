#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	cout << "分数" << endl;
	{
		Fraction f1(4, 5);
		double d = 5 + f1; // f 转换为 double
		Fraction f2 = f1 + 3;
	}
	return 0;
}