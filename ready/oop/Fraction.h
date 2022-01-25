#ifndef __FRACTION_H_INCLUDED__
#define __FRACTION_H_INCLUDED__

#include <iostream>
using namespace std;

class Fraction 
{
public:
	Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
	// conversion function
	operator double() const {
		std::cout << "conversion function" << std::endl;
		return (double) (m_numerator / m_denominator);
	}

private:
	int m_numerator;
	int m_denominator;
};


#endif
