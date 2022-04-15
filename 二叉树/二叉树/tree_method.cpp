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
//当栈不为空时，栈顶元素出栈，如果其右孩子不为空，
//则右孩子入栈，其左孩子不为空，则左孩子入栈
void pre_traverse(BTree pTree)
{
	PSTACK stack = create_stack();
	BTree node_pop;
	BTree pCur = pTree;
	while (pCur || !is_empty(stack))
	{
		if (pCur)
		{
			printf("%c", pCur->data);
			push_stack(stack, pCur);
			pCur = pCur->pLchild;
		}
		else
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

	while (pCur != NULL || !is_empty(stack))
	{
		if (pCur)
		{
			push_stack(stack, pCur);
			pCur = pCur->pLchild;
		}
		else
		{
			pCur = getTop(stack);
			printf("%c", pCur->data);
			pop_stack(stack, &node_pop);
			pCur = pCur->pRchild;
		}
	}
}
/*
后序遍历的非递归实现

后序遍历的难点在于：需要判断上次访问的节点是位于左子树，还是右子树。
若是位于左子树，则需跳过根节点，先进入右子树，再回头访问根节点；
若是位于右子树，则直接访问根节点。
*/
void beh_traverse(BTree pTree)
{
	PSTACK stack = create_stack();
	BTree node_pop;
	BTree pCur ;
	BTree pPre = NULL;

	
	pCur = pTree;
	while (pCur)
	{
		pCur = pCur->pLchild;
	}
	while (!is_empty(stack))
	{
		pCur = getTop(stack);
		pop_stack(stack, &node_pop);
		if (pCur->pRchild == NULL || pCur->pRchild == pPre)
		{
			
			printf("%c", pCur->data);
			pPre = pCur;
		}
		else
		{
			push_stack(stack, pCur);
			pCur = pCur->pRchild;
			while (pCur)
			{
				push_stack(stack, pCur);
				pCur = pCur->pLchild;

			}
		}

	}
}