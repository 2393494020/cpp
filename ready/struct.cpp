#include <iostream>
#include <time.h>

using namespace std;

// cpp 的结构体可以 new
// 没有关键字 typedef 使用结构体类型也可以不加 struct

typedef struct _node
{
	int data;
	struct _node* next;
} Node, * LinkList;


bool init_linklist(LinkList& l)
{
	l = new Node;
	if (l == NULL)
	{
		return false;
	}
	l->next = NULL;
	return true;
}

// 头插法
void insert_linklist_head(LinkList& l, int data)
{
	if (!l)
	{
		return;
	}
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = l->next;

	l->next = new_node;
}

// 尾插法
void insert_linklist_tail(LinkList& l, int data)
{
	if (!l)
	{
		return;
	}
	Node* p = l;
	while (p->next)
	{
		p = p->next;
	}

	p->next = new Node;
	p->next->data = data;
	p->next->next = NULL;
}

void print_linklist(LinkList l)
{
	if (l == NULL)
		return;

	while (l->next)
	{
		printf("%d", l->next->data);
		l = l->next;
		if (l->next == NULL)
			printf("\n");
		else
			printf(" ");
	}
}

int locate_element(LinkList l, int item)
{
	if (l == NULL)
		return -1;
	
	int i = 1;
	while (l->next)
	{
		if (l->next->data == item)
		{
			return i;
		}
		i++;
		l = l->next;
	}
	return -1;
}

void remove_element(LinkList l, int index)
{
	if (l == NULL || index <= 0)
	{
		return;
	}

	int i = 1;
	while (i < index && l->next)
	{		
		i++;
		l = l->next;
	}
	
	Node* target = l->next;

	if (!target)
	{
		return;
	}

	l->next = target->next;
	target->next = NULL;

	delete target;
}

// 合并两个有序链表
// 合并后的新链表依然有序
void merge_linklist(LinkList lx, LinkList ly, LinkList l)
{
	Node* px = lx;
	Node* py = ly;
	// if (px->data < py->data)
	// {
	// 	l->next = px->next;
	// }
	// else
	// {
	// 	l->next = py->next;
	// }
	Node* p = l;

	while (px->next && py->next)
	{
		if (px->next->data < py->next->data)
		{
			p->next = px->next;
			px = px ->next;
		}
		else
		{
			p->next = py->next;
			py = py ->next;
		}
		cout << p << endl;
	}
}

void destory_linklist(LinkList& l)
{
	if (l == NULL)
		return;
	
	Node* p = l;
	while (p->next)
	{
		Node* tmp = p->next;
		p->next = NULL;
		delete p;

		p = tmp;
	}

	delete p;
	l = NULL;
}

#define LL_SIZE 10
#define RANGE 100

#if 1
int main()
{
	LinkList l, lx, ly;
	init_linklist(l);
	init_linklist(lx);
	init_linklist(ly);
		
	for (int i = 0; i < LL_SIZE; i++)
	{
		if ((i + 1) % 2 == 1)
			insert_linklist_tail(lx, i + 1);
		else
			insert_linklist_tail(ly, i + 1);
	}

	cout << "链表一" << endl;
	print_linklist(lx);
	
	cout << "链表二" << endl;
	print_linklist(ly);

	merge_linklist(lx, ly, l);

	cout << "合并后" << endl;
	print_linklist(l);

	//destory_linklist(l);
	return 0;
}
#endif

#if 0
int main()
{
	LinkList l;

	bool init_result = init_linklist(l);
	if (!init_result)
	{
		exit(1);
	}

	int seed = time(0);
	srand((unsigned int) seed);
	
	cout << "头插法" << endl;
	for (int i = 0; i < LL_SIZE; i++)
	{
		int rand_num = rand() % RANGE;
		printf("%d", rand_num);
		if (i == LL_SIZE - 1)
			printf("\n");
		else
			printf(" ");
		insert_linklist_head(l, rand_num);
	}

	print_linklist(l);

	cout << "尾插法" << endl;
	for (int i = 0; i < LL_SIZE; i++)
	{
		int rand_num = rand() % RANGE;
		printf("%d", rand_num);
		if (i == LL_SIZE - 1)
			printf("\n");
		else
			printf(" ");
		insert_linklist_tail(l, rand_num);
	}

	print_linklist(l);
	
	int item = rand() % RANGE;
	cout << "输入你想定位的数据:";
	cin >> item;
	cout << item << " 在第 " << locate_element(l, item) << " 位" << endl;
	

	cout << "输入你想删除的数据位置:";
	cin >> item;
	remove_element(l, item);

	cout << "删除数据后的链表" << endl;
	print_linklist(l);

	destory_linklist(l);

	cout << "end" << endl;

	return 0;
}
#endif