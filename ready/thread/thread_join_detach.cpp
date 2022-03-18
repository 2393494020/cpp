#include <iostream>
#include <thread>
#include <windows.h>

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
	void operator()() const;
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

void TreadChild::operator()() const
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
	// 子线程的对象是主线程的对象副本, 所以当主线程结束运行时, 主线程的对象被销毁不影响子线程的对象副本
	thread t(tc);
	t.join();
	return 0;
}

#endif

#if 0

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
	return 0;
}

#endif

#if 1
// 给线程调用函数传参
// 1. 引用传递最终也是值传递
// 2. 如果用 detach, 传指针时避免子线程指向主线程栈空间资源
// 3. 传对象时, 直接传构造好的对象, 避免隐式类型转换

void print_plus(const int& i, const char* pc)
{
	cout << "child &i = " << &i << endl;
	printf("child &hello = %p\n", pc);
}

void print_pp(const int& i, const string& hello)
{
}

class Integer
{
public:
	mutable int _i;

	Integer(int i) : _i(i)
	{
		cout << this << " Integer(int i)" << " in thread:" << std::this_thread::get_id() << endl;
	}

	Integer(const Integer& integer) : _i(integer._i)
	{
		cout << this << " copy from " << &integer << " in thread:" << std::this_thread::get_id() << endl;
	}

	~Integer()
	{
		cout << this << " ~Integer()" << " in thread:" << std::this_thread::get_id() << endl;
	}

	void print_integer()
	{
		Sleep(100);
		cout << this << " print_integer in thread:" << std::this_thread::get_id() << endl;
	}
};

void print_integer(const Integer& integer)
{
	Sleep(100);
	integer._i = 199;
	cout << &integer << " print_integer in thread:" << std::this_thread::get_id() << endl;
}

int main()
{
	int i = 99;
	char hello[] = {"hello cpp"};

	cout << "main &i = " << &i << endl;
	cout << "main &hello = " << &hello << endl;

	// thread t1(print_plus, i, hello);
	// t1.join(); // 避免 detach
	
	// thread t2(print_pp, i, hello); // bug隐患, 有可能主线程执行完, 隐式转换还没完成( hello 会在子线程传入 string 构造函数, 创建出新的 string 对象 )
	// t2.detach();

	// thread t3(print_pp, i, string(hello)); // 传递用构造对象
	// t3.detach();

	// 验证
	cout << "main thread:" << std::this_thread::get_id() << endl;
	// thread t4(print_integer, Integer(i)); // 1. Integer 类的匿名临时对象在主线程构造完成; 2. 调用拷贝构造函数创建对象副本传给子线程
	// t4.join();

	// 子线程修改主线程的变量值 std::ref
	// Integer mi(i);
	// thread t5(print_integer, std::ref(mi));
	// t5.join();
	// cout << mi._i << endl;

	// 子线程调用类的成员方法
	Integer ti(i);
	thread t6(&Integer::print_integer, ti);
	t6.join();
	return 0;
}

#endif
