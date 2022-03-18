#include <iostream>
#include <thread>
#include <windows.h>

using namespace std;

// �������߳�
// 1. ����
// 2. ��
// 3. lambda ���ʽ
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
	thread t(greeting); // ���ú�����Ϊ��ִ�ж��󴴽�һ�����̲߳�ִ��
	//t.join(); // �������߳�, �ȴ����߳�ִ�н���
	t.detach(); // �����̷߳���, ���̲߳��ٿ������߳�, ���߳�������ʱ�⸺������; ���̲߳�Ҫָ�����̵߳���Դ, �������������Ԥ�ϵĺ��
	
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
	// ���̵߳Ķ��������̵߳Ķ��󸱱�, ���Ե����߳̽�������ʱ, ���̵߳Ķ������ٲ�Ӱ�����̵߳Ķ��󸱱�
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
// ���̵߳��ú�������
// 1. ���ô�������Ҳ��ֵ����
// 2. ����� detach, ��ָ��ʱ�������߳�ָ�����߳�ջ�ռ���Դ
// 3. ������ʱ, ֱ�Ӵ�����õĶ���, ������ʽ����ת��

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
	// t1.join(); // ���� detach
	
	// thread t2(print_pp, i, hello); // bug����, �п������߳�ִ����, ��ʽת����û���( hello �������̴߳��� string ���캯��, �������µ� string ���� )
	// t2.detach();

	// thread t3(print_pp, i, string(hello)); // �����ù������
	// t3.detach();

	// ��֤
	cout << "main thread:" << std::this_thread::get_id() << endl;
	// thread t4(print_integer, Integer(i)); // 1. Integer ���������ʱ���������̹߳������; 2. ���ÿ������캯���������󸱱��������߳�
	// t4.join();

	// ���߳��޸����̵߳ı���ֵ std::ref
	// Integer mi(i);
	// thread t5(print_integer, std::ref(mi));
	// t5.join();
	// cout << mi._i << endl;

	// ���̵߳�����ĳ�Ա����
	Integer ti(i);
	thread t6(&Integer::print_integer, ti);
	t6.join();
	return 0;
}

#endif
