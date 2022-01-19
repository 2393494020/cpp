#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	int* pa = &a;
	cout << pa << endl;
	cout << *pa << endl;

	char str_arr[] = { "hello world" }; // arr 变量不可以重新赋值, 但里边的内容可以修改, 数组名是右值
	const char* pstr = "hello world";   // pstr 里边的内容是常量, 不可以修改；但 pstr 可以重新指向新的地址

	str_arr[0] = 'H';
	pstr = "hello cpp";
	
	cout << str_arr << endl;
	cout << pstr << endl;

	pstr = str_arr;
	cout << pstr << endl;
	cout << pstr[0] << endl;

	pstr = NULL;

	// 数组指针与二维数组

	int int_arr[] = { 10, 20, 30, 40, 50 };
	pa = int_arr;

	cout << *++pa << endl;
	cout << *pa++ << endl; // 区别于 (*pa)++
	cout << *pa << endl;

	*pa++ = 99;
	cout << *pa << endl;
	
	for (int i = 0; i < 5; i++) {
		cout << "int_arr[" << i << "] = " << int_arr[i]  << endl;
	}
	return 0;
}