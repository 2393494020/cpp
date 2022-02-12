#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <string.h>

using namespace std;

class String
{
public:
	String(const char* cdata);
	// 拷贝构造函数
	String(const String& source);
	// assign 操作符
	String& operator = (const String& source);
	// 析构
	~String();

	char* get_c_str() const
	{
		return c_data;
	}
private:
	char* c_data;
};

String::String(const char* cdata = 0)
{
	if (cdata)
	{
		c_data = new char[strlen(cdata) + 1];
		strcpy(c_data, cdata);
	}
	else
	{
		c_data = new char[1];
		*c_data = '\0';
	}
}

String::String(const String& source)
{
	c_data = new char[strlen(source.c_data) + 1];
	strcpy(c_data, source.c_data);
}

String& String::operator = (const String& source)
{
	// 如果不做该判断
	// 自己赋值给自己执行后面的语句会被清空
	if (this == &source)
	{
		return *this;
	}

	delete[] c_data;
	c_data = new char[strlen(source.c_data) + 1];
	strcpy(c_data, source.c_data);
	return *this;
}

String::~String()
{
	cout << "String::~String" << endl;
	if (c_data != nullptr) {
		delete[] c_data;
		c_data = nullptr;
	}
}

#endif