//定义二叉树表示方法
typedef struct BTNode
{
	char data;
	struct BTNode* pLchild;
	struct BTNode* pRchild;
}BTNode,*BTree;


//创建一棵二叉树
BTree creat_tree();
//非递归实现二叉树的前序遍历
void pre_traverse(BTree);
//非递归实现二叉树的中序遍历
void in_traverse(BTree);
//非递归实现二叉树的后序遍历
void beh_traverse(BTree);

//定义栈的表示方法
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

//创建空栈的函数
PSTACK create_stack();
//入栈函数
void push_stack(PSTACK, BTree);//BTree为数据的类型
//遍历栈
void traverse_stack(PSTACK);
//判断栈空函数
bool is_empty(PSTACK);
//清空栈
void clear_stack(PSTACK);
//取栈顶元素
BTree get_top(STACK);