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



