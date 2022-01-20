#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s0;
	string s1 = "hello";
	string s2 = string("world");

	cout << s0.length() << endl;
	cout << s0.size() << endl;
	cout << s0.capacity() << endl;

	s1 += " " + s2;
	cout << s1 << endl;
}
