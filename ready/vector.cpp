#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 1, 2, 3 };

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.push_back(4);
	v.push_back(5);

	cout << v.size() << endl;
	cout << v.capacity() << endl;
}