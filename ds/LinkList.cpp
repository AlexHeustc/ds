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
//ɾ��Ԫ��
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

//����������
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
	//��ʼ��
	InitList(L);
	//ͷ�巨����
	int n = 0;
	cout << "������Ҫ�����Ԫ�ظ�����" << endl;
	cin >> n;
	cout << "����������" << n << "��Ԫ�أ�" << endl;
	while (n > 0)
	{
		s = new LinkNode;	//�����µĽڵ�s
		cin >> s->data;
		Push_front(L, s);
		n--;
	}
	//��ӡ
	ListPrint(L);
	cout << "---------------------" << endl;

	//β�巨����
	cout << "������Ҫ�����Ԫ�ظ�����" << endl;
	cin >> n;
	cout << "����������" << n << "��Ԫ�أ�" << endl;
	while (n > 0)
	{
		s = new LinkNode;	//�����µĽڵ�s
		cin >> s->data;
		Push_back(L, s);
		n--;
	}
	//��ӡ
	ListPrint(L);

	//����λ�ò���
	int x = 0;
	cout << "������Ҫ�����λ�ã�" << endl;
	cin >> n;
	cout << "������Ԫ�أ�" << endl;
	cin >> x;
	ListInsert(L, n, x);
	ListPrint(L);

	//ȡ��Ԫ��
	cout << "������Ҫȡ���ڼ�λԪ�أ�" << endl;
	cin >> n;
	int a = 0;
	Link_elem(L, n, a);
	cout << "ȡ���ĵ�" << n << "λԪ��Ϊ��" << a << endl;

	//ɾ��Ԫ��
	cout << "������Ҫɾ���ڼ���Ԫ�أ�" << endl;
	cin >> n;
	LinkDelete(L, n);
	ListPrint(L);

	//��������
	LinkDestory(L);


	system("pause");
	return 0;
}






