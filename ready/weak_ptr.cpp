#include <iostream>
#include <memory>

using namespace std;

struct B;
struct A
{
	shared_ptr<B> pb;
	~A()
	{
		cout << "~A" << endl;
	}
};

struct B
{
	shared_ptr<A> pa;
	~B()
	{
		cout << "~B" << endl;
	}
};


struct WB;
struct SA
{
	shared_ptr<WB> pb;
	~SA()
	{
		cout << "~SA" << endl;
	}
};

struct WB
{
	weak_ptr<SA> pa;
	~WB()
	{
		cout << "~WB" << endl;
	}
};

int main()
{
	// shared_ptr 相互引用无法释放
	// weak_ptr 相当于观察者模式
	{
		shared_ptr<A> spa(new A);
		shared_ptr<B> spb(new B);

		cout << spa.use_count() << endl;
		cout << spb.use_count() << endl;

		spa->pb = spb;
		spb->pa = spa;

		cout << spa.use_count() << endl;
		cout << spb.use_count() << endl;
	} // 结束该域, 析构函数不被调用, 内存泄漏
	
	cout << "use weak_ptr" << endl;
	{
		shared_ptr<SA> spa(new SA);
		shared_ptr<WB> wpb(new WB);

		cout << spa.use_count() << endl;
		cout << wpb.use_count() << endl;

		spa->pb = wpb;
		wpb->pa = spa;

		cout << spa.use_count() << endl;
		cout << wpb.use_count() << endl;
	}
	
	return 0;
}
