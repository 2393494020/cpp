#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
	{
		auto_ptr<int> pi(new int(10));
		cout << *pi << endl;
		
		auto_ptr<string> pstrs[] = {
			auto_ptr<string>(new string("cpp")),
			auto_ptr<string>(new string("java")),
			auto_ptr<string>(new string("python"))
		};
		for (int i = 0; i < 3; i++)
		{
			cout << *pstrs[i] << endl;
		}
		
		auto_ptr<string> pstr_java;
		pstr_java = pstrs[1]; // pstrs[1] -> nullptr
		for (int i = 0; i < 3; i++)
		{
			cout << *pstrs[i] << endl;
		}
	}
	return 0;
}