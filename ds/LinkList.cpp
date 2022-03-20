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


}
