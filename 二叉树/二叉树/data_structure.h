//�����������ʾ����
typedef struct BTNode
{
	char data;
	struct BTNode* pLchild;
	struct BTNode* pRchild;
}BTNode,*BTree;


//����һ�ö�����
BTree creat_tree();
//�ǵݹ�ʵ�ֶ�������ǰ�����
void pre_traverse(BTree);
//�ǵݹ�ʵ�ֶ��������������
void in_traverse(BTree);
//�ǵݹ�ʵ�ֶ������ĺ������
void beh_traverse(BTree);

//����ջ�ı�ʾ����
typedef struct NODE
{
	BTree data;
	struct NODE *pNext;
}BNODE,*PNODE;

typedef struct STACK
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;

//������ջ�ĺ���
PSTACK create_stack();
//��ջ����
void push_stack(PSTACK, BTree);//BTreeΪ���ݵ�����
//����ջ
void traverse_stack(PSTACK);
//�ж�ջ�պ���
bool is_empty(PSTACK);
//���ջ
void clear_stack(PSTACK);
//ȡջ��Ԫ��
BTree get_top(STACK);