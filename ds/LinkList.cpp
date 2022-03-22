#include<iostream>

using namespace std;

typedef struct _Linknode {
	int data; //节点的数据域
	struct _Linknode* next; //节点的指针域
}LinkNode,Linklist;//LinkNode为指向结构体的指针类型

//初始化
bool InitList(Linklist*& L) {
	L = new LinkNode;
	if (!L)
	{
		return false;
	}
	L->next = NULL;
	return true;
}

//前插法
bool Push_front(Linklist*& L, LinkNode* node) {
	if (!L || !node) return false;
	
	node->next = L;
	L->next = NULL;

}

//尾插法
bool Push_back(Linklist*& L, LinkNode* node) {
	if (!L || !node) return false;
	
	Linklist* last = NULL;
	last = L->next;

	while (last->next)
	{
		last = last->next;

	}
	last->next = node;
	node->next = NULL;

	return true;
}

//任意位置插入
bool ListInsert(Linklist*& L, int i, int& e) {
	if (!L)
	{
		return false;
	}

	int j = 0;
	Linklist* p = L;

	while (p && j != i - 1) {//查找第i-1个节点，使p指向该节点

		p = p->next;
		j++;
	}

	if (!p || j > i - 1)
	{
		return false;

	}

	//生成新的节点
	Linklist* s = new LinkNode;
	s->data = e;
	s->next = p->next;
	p->next = s;

}

//打印
void ListPrint(Linklist*& L) {

	if (!L)
	{
		cout << "链表为空！" << endl;
		return;
	}

	Linklist* p = NULL;
	p = L;
	while (!p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

}

//取出位置为i的元素
bool Link_elem(Linklist*& L,int i,int &e) {

	if (!L || !L->next)
	{
		return false;
	}

	int j = 1;
	Linklist* p = L->next;

	while (p && j < i) 
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		return false;
	}
	e = p->data;
	return true;

}
bool Linkfind(Linklist*& L, int e) {
	
	if (!L) return false;
	Linklist* p = L;
	
	while (p && p->data !=e)
	{
		p = p->next;


	}
	if (!p) return false;

	return true;
	
}
//删除元素
bool LinkDelete(Linklist*& L, int i)
{
	if (!L)
	{
		return false;
	}
	int j = 0;

	Linklist* p = L;
	while (!p && j<i-1)
	{
		p = p->next;
	}
	if (!(p->next) || (j > i - 1))
	{
		return false;
	}
	Linklist* s = p->next;
	p->next = s;
	delete s;
	return true;
}

//单链表销毁
bool LinkDestory(Linklist*& L)
{
	if (!L)
	{
		return false;
	}
	Linklist* p=L;
	while (p)
	{
		L = L->next;
		delete p;
		p = L;
	}

}

int main()
{
	Linklist* L = NULL;
	Linklist* s = NULL;
	//初始化
	InitList(L);
	//头插法插入
	int n = 0;
	cout << "请输入要插入的元素个数：" << endl;
	cin >> n;
	cout << "请依次输入" << n << "个元素：" << endl;
	while (n > 0)
	{
		s = new LinkNode;	//生成新的节点s
		cin >> s->data;
		Push_front(L, s);
		n--;
	}
	//打印
	ListPrint(L);
	cout << "---------------------" << endl;

	//尾插法插入
	cout << "请输入要插入的元素个数：" << endl;
	cin >> n;
	cout << "请依次输入" << n << "个元素：" << endl;
	while (n > 0)
	{
		s = new LinkNode;	//生成新的节点s
		cin >> s->data;
		Push_back(L, s);
		n--;
	}
	//打印
	ListPrint(L);

	//任意位置插入
	int x = 0;
	cout << "请输入要插入的位置：" << endl;
	cin >> n;
	cout << "请输入元素：" << endl;
	cin >> x;
	ListInsert(L, n, x);
	ListPrint(L);

	//取出元素
	cout << "请输入要取出第几位元素：" << endl;
	cin >> n;
	int a = 0;
	Link_elem(L, n, a);
	cout << "取出的第" << n << "位元素为：" << a << endl;

	//删除元素
	cout << "请输入要删除第几个元素：" << endl;
	cin >> n;
	LinkDelete(L, n);
	ListPrint(L);

	//销毁链表
	LinkDestory(L);


	system("pause");
	return 0;
}






