#include <iostream>
#include <memory>

using namespace std;

int main()
{
	auto k = unique_ptr<int>(new int(20));
	cout << *k << endl;
	cout << *(k.get()) << endl;

	auto i = make_unique<int>(10);
	cout << &i << endl;
	cout << (i.get()) << endl;
	cout << *(i.get()) << endl;
	// auto j = i; // 不能通过赋值语句获取 i 所指的地址

	auto j = move(i); // std::move 方法将 i 所指地址移给 j
	cout << *(j.get()) << endl;
	cout << "i = " << (i.get() == nullptr ? -1 : *(i.get())) << endl;
}