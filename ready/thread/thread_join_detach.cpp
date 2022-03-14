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
	TreadChild(TreadChild& tc);
	void operator()();
	~TreadChild();
};

TreadChild::TreadChild()
{
	cout << "TreadChild():" << this << endl;
}

TreadChild::TreadChild(TreadChild& source)
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
	// 1. ��Ҫ��������ʱ������Ϊ�����������߳�
	// 2. ���̵߳Ķ��������̵߳Ķ��󸱱�, ���Ե����߳̽�������ʱ, ���߳��еĶ���û�б�����
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