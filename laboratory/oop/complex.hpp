#ifndef __COMPLEX_HPP_INCLUDED__
#define __COMPLEX_HPP_INCLUDED__

class complex
{
public:
	complex(int a, int b);
	complex& operator+=(const complex& f);
	int x_();
	int y_();
private:
	int x;
	int y;
};

#endif