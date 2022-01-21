#include <iostream>
#include <memory>

using namespace std;

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
	return 0;
}
