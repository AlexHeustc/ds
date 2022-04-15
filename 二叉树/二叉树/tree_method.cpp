#include<stdio.h>
#include<stdlib.h>
#include"data_structure.h"

//����һ�ö�����
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
ǰ������ķǵݹ�ʵ��
*/
//��ջ��Ϊ��ʱ��ջ��Ԫ�س�ջ��������Һ��Ӳ�Ϊ�գ�
//���Һ�����ջ�������Ӳ�Ϊ�գ���������ջ
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
����ķǵݹ�ʵ��
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
��������ķǵݹ�ʵ��

����������ѵ����ڣ���Ҫ�ж��ϴη��ʵĽڵ���λ����������������������
����λ���������������������ڵ㣬�Ƚ������������ٻ�ͷ���ʸ��ڵ㣻
����λ������������ֱ�ӷ��ʸ��ڵ㡣
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