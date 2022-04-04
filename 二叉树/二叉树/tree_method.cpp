#include<stdio.h>
#include<stdlib.h>
#include"data_structure.h"

//创建一棵二叉树
BTree create_tree()
{
	BTree pA = (BTree)malloc(sizeof(BTNode));
	BTree pB = (BTree)malloc(sizeof(BTNode));
	BTree pD = (BTree)malloc(sizeof(BTNode));
	BTree pE = (BTree)malloc(sizeof(BTNode));
	BTree pC = (BTree)malloc(sizeof(BTNode));
	BTree pF = (BTree)malloc(sizeof(BTNode));

	pA->data = 'A';
	pB->data = 'B';
	pD->data = 'D';
	pE->data = 'E';
	pC->data = 'C';
	pF->data = 'F';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pD;
	pB->pRchild = pE;
	pD->pLchild = pD->pRchild = NULL;
	pE->pLchild = pE->pRchild = NULL;
	pC->pLchild = pF;
	pC->pRchild = NULL;
	pF->pLchild = pF->pRchild = NULL;

	return pA;
}

/*
前序遍历的非递归实现
*/
void pre_traverse(BTree pTree)
{
	PSTACK stack = create_stack();//创建一个空栈
	BTree node_pop;//用来保存出栈数据
	BTree pCur = pTree;//定义用来指向当前访问节点的指针

	//直到当前节点pCur为NULL且栈为空，循环结束
	while (pCur || !is_empty(stack))
	{

	}
}