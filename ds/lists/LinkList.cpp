#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;

// 初始化
bool InitList_L(LinkList& L)
{
	L = new LNode;
	if (!L)
		return false;
	L->next = NULL;
	return true;
}

// 头插法
bool Create_LinkList_H(LinkList& L, int n)
{
	cout << "generate random elements:";
	while (n)
	{
		int randomNum = rand() % n + 1;
		cout << randomNum << " ";
		LinkList p = new LNode;
		p->data = randomNum;
		p->next = L->next;
		L->next = p;
		n--;
	}

	cout << endl;

	return true;
}

// 尾插法
bool Create_LinkList_T(LinkList& L, int n)
{
	cout << "generate random elements:";
	LinkList t = L;
	while (n)
	{
		int randomNum = rand() % n + 1;
		cout << randomNum << " ";
		LinkList p = new LNode;
		p->data = randomNum;
		p->next = NULL;
		t->next = p;
		t = p;
		n--;
	}

	cout << endl;

	return true;
}

// 定位
int Location_LinkList_E(LinkList& L, int e)
{
	LinkList p = L->next;
	int i = 1;
	while (p)
	{
		if (p->data == e)
			break;
		p = p->next;
		i++;
	}

	if (!p)
		return 0;
	else
		return i;
}

// 获取
bool Get_LinkList_E(LinkList& L, int index, int& e)
{
	LinkList p = L->next;
	int i = 1;
	while (p && i < index)
	{
		p = p->next;
		i++;
	}

	if (i == index && p)
	{
		e = p->data;
	}
	else
	{
		return false;
	}

	return true;
}

// 删除
bool Delete_LinkList_E(LinkList& L, int index)
{
	LinkList p = L;
	int i = 0;
	while (p->next && i <= index - 1)
	{
		if (i == index - 1)
		{
			LinkList temp = p->next;
			p->next = temp->next;
			delete temp;
			break;
		}
		p = p->next;
		i++;
	}

	return true;
}

// 插入
bool Insert_LinkList_E(LinkList& L, int index, int data)
{
	LinkList p = L;
	int i = 0;
	while (p && i <= index - 1)
	{
		if (i == index - 1)
		{
			LinkList temp = new LNode;
			temp->data = data;
			temp->next = p->next;
			p->next = temp;
			break;
		}
		p = p->next;
		i++;
	}

	if (!p)
		return false;

	return true;
}

void Print_L(LinkList& L)
{
	LinkList p = L->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int Length_L(LinkList& L)
{
	int c = 0;
	LinkList p = L->next;
	while (p)
	{
		c++;
		p = p->next;
	}

	return c;
}

int main()
{
	unsigned seed = time(0);
	srand(seed); // 随机数种子

	LinkList L;
	InitList_L(L);
	cout << "type list size:";
	int n;
	cin >> n;
	Create_LinkList_T(L, n);
	cout << "length:" << Length_L(L) << endl;
	cout << "list elements:";
	Print_L(L);

	cout << "search element:";
	int e;
	cin >> e;
	int index = Location_LinkList_E(L, e);
	cout << "element " << e << " at " << index << endl;

	cout << "get element at:";
	int i;
	int result;
	cin >> i;
	bool status = Get_LinkList_E(L, i, result);
	if (status)
		cout << "result:" << result << endl;
	else
		cout << "cannot get element at:" << i << endl;
	
	cout << "delete element at:";
	cin >> i;
	Delete_LinkList_E(L, i);
	cout << "list elements:";
	Print_L(L);

	cout << "insert position and element:";
	cin >> i;
	cin >> e;
	Insert_LinkList_E(L, i, e);
	cout << "list elements:";
	Print_L(L);

	return 0;
}