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

//����λ�ò���
bool ListInsert(Linklist*& L, int i, int& e) {
	if (!L)
	{
		return false;
	}

	int j = 0;
	Linklist* p = L;

	while (p && j != i - 1) {//���ҵ�i-1���ڵ㣬ʹpָ��ýڵ�

		p = p->next;
		j++;
	}

	if (!p || j > i - 1)
	{
		return false;

	}

	//�����µĽڵ�
	Linklist* s = new LinkNode;
	s->data = e;
	s->next = p->next;
	p->next = s;

}

//��ӡ
void ListPrint(Linklist*& L) {

	if (!L)
	{
		cout << "����Ϊ�գ�" << endl;
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

//ȡ��λ��Ϊi��Ԫ��
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



