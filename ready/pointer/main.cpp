#include <iostream>

using namespace std;

int main() {
	int a = 10;
	int* pa = &a;
	cout << pa << endl;
	cout << *pa << endl;

	char str_arr[] = { "hello world" }; // arr �������������¸�ֵ, ����ߵ����ݿ����޸�, ����������ֵ
	const char* pstr = "hello world";   // pstr ��ߵ������ǳ���, �������޸ģ��� pstr ��������ָ���µĵ�ַ

	str_arr[0] = 'H';
	pstr = "hello cpp";
	
	cout << str_arr << endl;
	cout << pstr << endl;

	pstr = str_arr;
	cout << pstr << endl;
	cout << pstr[0] << endl;

	pstr = NULL;

	// ����ָ�����ά����

	int int_arr[] = { 10, 20, 30, 40 };
	pa = int_arr;

	cout << *++pa << endl;
	cout << *pa++ << endl; // ������ (*pa)++
	cout << *pa << endl;
	for (int i = 0; i < 4; i++) {
		cout << "int_arr[" << i << "] = " << int_arr[i]  << endl;
	}
	return 0;
}