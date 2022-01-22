#include <iostream>
#include <memory>
#include <assert.h>

using namespace std;

void swap_by_ref(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void swap_by_ptr(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int i = 10;
	int &ri = i; // ir 只是 i 的一个别名
	// i = 30;
	ri = 20;
	cout << i << endl;
	cout << ri << endl;
	// ir 与 i 的地址是一样的
	cout << &i << endl;
	cout << &ri << endl;
	cout << sizeof(i) << endl;
	cout << sizeof(ri) << endl;

	int a = 12, b = 37;
	swap_by_ref(a, b);
	assert(a == 37 && b == 12);
	swap_by_ptr(&a, &b);
	assert(a == 12 && b == 37);
	return 0;
}
