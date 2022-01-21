#include <iostream>
#include <string.h>

using namespace std;

int main() {
	const char* str = "hello world";
	char str_arr[15] = { "ha " };
	cout << strlen(str) << endl;

	strcat(str_arr, str); // strcat_s for windows
	cout << str_arr << endl;

	strcpy(str_arr, str); // strcpy_s for windows
	cout << str_arr << endl;
}
