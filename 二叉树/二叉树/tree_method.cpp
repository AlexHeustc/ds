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

	}
}