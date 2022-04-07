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
		//从根节点开始，输出当前节点，并将其入栈，
		//同时置其左孩子为当前节点，直至其没有左孩子，直到前节点为NULL
		printf("%c", pCur->data);
		push_stack(stack, pCur);
		pCur = pCur->pLchild;
		//如果当前节点pCur为NULL且栈不空，则将栈顶节点出栈，
		//同时置其右孩子为当前节点,循环判断，直至pCur不为空
		while (!pCur || !is_empty(stack))
		{
			pCur = getTop(stack);
			pop_stack(stack, &node_pop);
			pCur = pCur->pRchild;
		}
	}
}

/*
中序的非递归实现
*/
void in_traverse(BTree pTree)
{
	PSTACK stack = create_stack();
	BTree node_pop;
	BTree pCur = pTree;

	while (pCur || !is_empty(stack))
	{
		if (pCur->pLchild)
		{
			push_stack(stack, pCur->pLchild);
			pCur = pCur->pLchild;
		}
		else
		{
			printf("%c", pCur->data);
			pCur = pCur->pRchild;
			//如果为空，且栈不空，则将栈顶节点出栈，并输出该节点，
			//同时将它的右孩子设为当前节点，继续判断，直到当前节点不为空
			while (!pCur && !is_empty(stack))
			{
				pCur = getTop(stack);
				printf("%c", pCur->data);
				pop_stack(stack, &node_pop);
				pCur = pCur->pRchild;
			}
		}
		
	}
}
/*后序遍历的非递归实现*/
void beh_traverse(BTree pTree)
{
	PSTACK stack = create_stack();
	BTree node_pop;
	BTree pCur;
	BTree pPre = NULL;

	push_stack(stack, pTree);

	while (!is_empty(stack))
	{
		pCur = getTop(stack);
		if ((pCur->pLchild == NULL && pCur->pRchild == NULL) || 
			(pPre!= NULL && (pCur->pLchild==pPre)))
		{

		}
	}
}