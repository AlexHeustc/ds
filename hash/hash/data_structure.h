#define M 7
typedef int ElemType;

/*
�ù�ϣ��������ӷ������ͻ����
*/
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node,*pNode;

typedef struct HashNode
{
	pNode first;
}HashNode,*HashTable;

//������ϣ��
HashTable create_HashTable(int);

//�ڹ�ϣ���в�������
pNode search_HashTable(HashTable, ElemType);

//�������ݵ���ϣ��
bool insert_HashTable(HashTable, ElemType);

//�ӹ�ϣ����ɾ������
bool delete_HashTable(HashTable, ElemType);

//���ٹ�ϣ��
void destroy_HashTable(HashTable, int);