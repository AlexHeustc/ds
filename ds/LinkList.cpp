#include<iostream>

using namespace std;

typedef struct _Linknode {
	int data; //�ڵ��������
	struct _Linknode* next; //�ڵ��ָ����
}LinkNode,Linklist;//LinkNodeΪָ��ṹ���ָ������

//��ʼ��
bool InitList(Linklist*& L) {
	L = new LinkNode;
	if (!L)
	{
		return false;
	}
	L->next = NULL;
	return true;
}

//ǰ�巨
bool Push_front(Linklist*& L, LinkNode* node) {
	if (!L || !node) return false;
	
	node->next = L;
	L->next = NULL;

}

//β�巨
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

