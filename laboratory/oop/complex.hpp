#ifndef __COMPLEX_HPP_INCLUDED__
#define __COMPLEX_HPP_INCLUDED__

class complex
{
public:
	complex(int a, int b);
	complex& operator += (const complex&);
	int x_() const;
	int y_() const;
private:
	int x;
	int y;
};

#endif
