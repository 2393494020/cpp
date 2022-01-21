#include <iostream>

using namespace std;

int main()
{
	// const 离'谁'近表示'谁'不可以修改
	// const 修饰的对象先看左边，如果左边没有看右边
	char str_hello[] = { "hello" };
	char const* pstr1 = "world";           // 指针可以指向另一块地址但指针指向的内容不可修改, 等价于 const char* pstr1 = "world";
	// pstr1[0] = 'W';                     // 不可以修改所指内容
	pstr1 = str_hello;                     // 可以指向另一块地址
	// pstr1[0] = 'H';
	char* const pstr2 = str_hello;         // 指针不可以指向新地址, 所指内容可以修改
	// char* const pstr2 = "hello world";  // 所指内容不可修改, 不能将常量赋给 pstr2
	pstr2[0] = 'H';                        // 所指内容可以修改
	// pstr2 = pstr1;                      // 不可以指向新地址
	char const * const pstr3 = "world";    // 不可以指向新地址, 也不可以修改所指内容
	// pstr3 = str_hello;                  // 不可以指向新地址
	// pstr3[0] = 'W';                     // 不可以修改所指内容
	return 0;
}