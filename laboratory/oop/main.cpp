#include <iostream>
#include <stdio.h>
#include "complex.hpp"

int main()
{
	complex c1(10, 20);
	complex c2(30, 40);
	c1 += c2;
	std::cout << c1.x_() << "\n";
	std::cout << c1.y_() << "\n";
	//system("notepad");
	return 0;
}