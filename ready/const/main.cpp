#include <iostream>

using namespace std;

int main() {
	// const ��'˭'����ʾ'˭'�������޸�
	// const ���εĶ����ȿ���ߣ�������û�п��ұ�
	char str_hello[] = { "hello" };
	char const* pstr1 = "world";           // ָ�����ָ����һ���ַ��ָ��ָ������ݲ����޸�, �ȼ��� const char* pstr1 = "world";
	// pstr1[0] = 'W';                     // �������޸���ָ����
	pstr1 = str_hello;                     // ����ָ����һ���ַ
	// pstr1[0] = 'H';
	char* const pstr2 = str_hello;         // ָ�벻����ָ���µ�ַ, ��ָ���ݿ����޸�
	// char* const pstr2 = "hello world";  // ��ָ���ݲ����޸�, ���ܽ��������� pstr2
	pstr2[0] = 'H';                        // ��ָ���ݿ����޸�
	// pstr2 = pstr1;                      // ������ָ���µ�ַ
	char const * const pstr3 = "world";    // ������ָ���µ�ַ, Ҳ�������޸���ָ����
	// pstr3 = str_hello;                  // ������ָ���µ�ַ
	// pstr3[0] = 'W';                     // �������޸���ָ����
	return 0;
}