#include <iostream>

using namespace std;

// *p 当做左值的时候表示修改被指空间的内容
// *p 当做右值的时候表示获取被指空间的内容
int main()
{
	int a = 10;
	int* pa = &a;
	cout << *pa << endl;

	char str_arr[] = { "hello world" }; // str_arr 是常量, 不可以被重新赋值(不能做左值), 但里边的内容可以修改
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

	*pa++ = 99; // 相当于 *pa = 99; pa++
	cout << *pa << endl;
	
	for (int i = 0; i < 5; i++) {
		cout << "int_arr[" << i << "] = " << int_arr[i]  << endl;
	}

	// 万能指针
    void* pv = &a;
    printf("void* 指向 int 获取的值:%d\n", *(int*)pv);
	
	pv = str_arr;
    printf("void* 指向 char 获取的值:%s\n", (char*)pv);
	return 0;
}