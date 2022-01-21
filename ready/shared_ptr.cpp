#include <iostream>
#include <memory>

using namespace std;

int main()
{
	shared_ptr<int> sp(new int(200));
	cout << sp.use_count() << endl;
	{
		shared_ptr<int> spp = sp; // sp 控制权共享给了 spp, 引用计数+1
		cout << *spp << endl;
		cout << sp.use_count() << endl;
		cout << spp.use_count() << endl;
	} // 离开该区域, 引用计数-1
	cout << sp.use_count() << endl;
	cout << sp << endl;
	shared_ptr<int> spp = move(sp); // sp 控制权转移给了 spp, 引用计数为 0
	cout << spp << endl;
	cout << (sp == nullptr ? -1 : *sp) << endl;
	cout << "sp use count=" << sp.use_count() << endl;
	cout << "spp use count=" << spp.use_count() << endl;
	return 0;
}
