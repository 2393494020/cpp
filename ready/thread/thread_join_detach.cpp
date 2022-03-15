#include <iostream>
#include <thread>

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
	// 1. ��Ҫ��������ʱ������Ϊ�����������߳�
	// 2. ���̵߳Ķ��������̵߳Ķ��󸱱�, ���Ե����߳̽�������ʱ, ���߳��еĶ���û�б�����
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
	int _i;
	Integer()
	{
		cout << this << " Integer()" << endl;
	}

	Integer(int i) : _i(i)
	{
		cout << this << " Integer(int i)" << endl;
	}

	Integer(const Integer& integer) : _i(integer._i)
	{
		cout << this << " copy from " << &integer << endl;
	}

	~Integer()
	{
		cout << this << " ~Integer()" << endl;
	}

};

void print_integer(const int& i, const Integer& integer)
{
	cout << integer._i << endl;
}

int main()
{
	int i = 99;
	char hello[] = {"hello cpp"};

	cout << "main &i = " << &i << endl;
	cout << "main &hello = " << &hello << endl;

	// thread t1(print_plus, i, hello);
	// t1.join(); // ���� detach
	
	// thread t2(print_pp, i, hello); // bug����, �п������߳�ִ����, ��ʽת����û���
	// t2.detach();

	// thread t3(print_pp, i, string(hello)); // �����ù������
	// t3.detach();

	// ��֤
	thread t4(print_integer, i, Integer(i));
	t4.join();
	return 0;
}

#endif
