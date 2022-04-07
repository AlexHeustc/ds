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
void pre_traverse(BTree pTree)
{
	PSTACK stack = create_stack();//����һ����ջ
	BTree node_pop;//���������ջ����
	BTree pCur = pTree;//��������ָ��ǰ���ʽڵ��ָ��

	//ֱ����ǰ�ڵ�pCurΪNULL��ջΪ�գ�ѭ������
	while (pCur || !is_empty(stack))
	{
		//�Ӹ��ڵ㿪ʼ�������ǰ�ڵ㣬��������ջ��
		//ͬʱ��������Ϊ��ǰ�ڵ㣬ֱ����û�����ӣ�ֱ��ǰ�ڵ�ΪNULL
		printf("%c", pCur->data);
		push_stack(stack, pCur);
		pCur = pCur->pLchild;
		//�����ǰ�ڵ�pCurΪNULL��ջ���գ���ջ���ڵ��ջ��
		//ͬʱ�����Һ���Ϊ��ǰ�ڵ�,ѭ���жϣ�ֱ��pCur��Ϊ��
		while (!pCur || !is_empty(stack))
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
			//���Ϊ�գ���ջ���գ���ջ���ڵ��ջ��������ýڵ㣬
			//ͬʱ�������Һ�����Ϊ��ǰ�ڵ㣬�����жϣ�ֱ����ǰ�ڵ㲻Ϊ��
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
/*��������ķǵݹ�ʵ��*/
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