#include <iostream>
#include <memory>

using namespace std;

int main()
{
	shared_ptr<int> sp(new int(200));
	cout << sp.use_count() << endl;
	{
		shared_ptr<int> spp = sp; // 引用计算+1
		cout << *spp << endl;
		cout << sp.use_count() << endl;
		cout << spp.use_count() << endl;
	} // 离开该区域, 引用计数-1
	cout << sp.use_count() << endl;
	return 0;
}