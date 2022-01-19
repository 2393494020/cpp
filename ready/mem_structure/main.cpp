#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int num = 20;
	int* p0 = &num;
	int* p1 = new int(10);
	char* p2 = new char[10];
	strcpy_s(p2, 6, "hello");

	cout << *p1 << endl;
	cout << p2 << endl;

	if (p1 != nullptr)
	{
		delete p1;
		p1 = nullptr;
	}

	if (p2 != nullptr)
	{
		delete[] p2;
		p2 = nullptr;
	}

	return 0;
}