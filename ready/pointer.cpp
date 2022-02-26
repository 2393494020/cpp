#include <iostream>

using namespace std;

// *p 当做左值的时候表示修改被指空间的内容
// *p 当做右值的时候表示获取被指空间的内容

void str_cpy(char* str_dest, const char* str_source)
{
	// while(*str_source)
	// {
	// 	*str_dest++ = *str_source++;
	// }

	while(*str_dest++ = *str_source++);
}

int main()
{
	int a = 10;
	int* pa = &a;
	cout << *pa << endl;

	char c_arr[] = { "hello world" };   // c_arr 是指向数组首元素的常量指针, 不可以被重新赋值(不能做左值), 但里边的内容可以修改
	const char* pstr = "hello world";   // pstr 里边的内容是常量, 不可以修改；但 pstr 可以重新指向新的地址

	str_cpy(c_arr, "hello china");
	c_arr[0] = 'H';
	pstr = "hello cpp";
	
	cout << c_arr << endl;
	cout << pstr << endl;

	pstr = c_arr;
	cout << pstr << endl;
	cout << pstr[0] << endl;

	// 以下两种情况发生时, 数组名不是指向数组首元素的地址
	// 1. sizeof
	// 2. 取数组地址时

	cout << "sizeof(c_arr) = " << sizeof(c_arr) << endl;
	cout << "&c_arr = " << &c_arr << endl;
	cout << "(&c_arr + 1) = " << (&c_arr + 1) << endl;

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
	
	pv = c_arr;
        printf("void* 指向 char 获取的值:%s\n", (char*)pv);
	
	// 指针数组(二级指针)
	string str_arr[] = {
		"hello",
		"china"
	};
	cout << *(str_arr + 0) << endl;
	cout << *(str_arr + 1) << endl;

	char str_empty[64] = { 0 }; // 习惯性初始化
	str_cpy(str_empty, "hello world");
	cout << str_empty << endl;
	return 0;
}
