#include <iostream>
#include <thread>

using namespace std;

// 创建子线程
// 1. 函数
// 2. 类
// 3. lambda 表达式
#if 0
void greeting()
{
	for (int i = 1; i <= 3; i++)
	{
		cout << "greeting " << i << endl;
	}
}

int main()
{
	thread t(greeting); // 利用函数做为可执行对象创建一个子线程并执行
	//t.join(); // 阻塞主线程, 等待子线程执行结束
	t.detach(); // 与子线程分离, 主线程不再控制子线程, 子线程由运行时库负责清理; 子线程不要指向主线程的资源, 否则会引发不可预料的后果
	
	for (int i = 1; i <= 3; i++)
	{
		cout << "i love china " << i << endl;
	}
	return 0;
}

#endif

#if 0

class TreadChild
{
public:
	TreadChild();
	TreadChild(const TreadChild& tc);
	void operator()();
	~TreadChild();
};

TreadChild::TreadChild()
{
	cout << "TreadChild():" << this << endl;
}

TreadChild::TreadChild(const TreadChild& source)
{
	cout << this << " copy from " << &source << endl;
}

void TreadChild::operator()()
{
	for (int i = 1; i <= 3; i++)
	{
		cout << "operator() " << i << endl;
	}
}

TreadChild::~TreadChild()
{
	cout << "~TreadChild():" << this << endl;
}

int main()
{
	TreadChild tc;
	// 1. 不要将匿名临时对象做为参数创建子线程
	// 2. 子线程的对象是主线程的对象副本, 所以当主线程结束运行时, 子线程中的对象没有被销毁
	thread t(tc);
	t.join();
}

#endif

#if 1

int main()
{
	auto lambdaT = []
	{
		for (int i = 1; i <= 3; i++)
		{
			cout << "lambda " << i << endl;
		}
	};
	thread t(lambdaT);
	t.join();
}

#endif
