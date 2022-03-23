#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE,*PNODE;

typedef struct Queue
{
	PNODE front;
	PNODE rear;
}QUEUE,*PQUEUE;

PQUEUE create_queue();
bool is_empty(PQUEUE);
void en_queue(PQUEUE, int);
bool de_queue(PQUEUE, int*);
void destroy_queue(PQUEUE);
void traverse_queue(PQUEUE);

int main()
{
	int data_de = 0;         //����������ӵ�Ԫ��ֵ

	//�������в�������Ӳ���
	PQUEUE pS = create_queue();
	en_queue(pS, 2);
	en_queue(pS, 4);
	en_queue(pS, 6);
	traverse_queue(pS);

	//���Ӳ���
	if (de_queue(pS, &data_de))
		printf("delete succeed,the deleted data is: %d\n", data_de);
	else
		printf("queue is empty! delete falied!\n");
	traverse_queue(pS);

	//���ٶ��в���
	destroy_queue(pS);
	printf("queue destroyed!\n");
	traverse_queue(pS);

	return 0;
}

/*
����һ���ն��У���ͷָ��Ͷ�βָ�붼ָ��ͷ��㣬
ͷ����в�������ݣ�ֻ���ָ��
*/

PQUEUE create_queue()
{
	PQUEUE pS = new QUEUE;
	pS->front = new NODE;

	if (!pS || !pS->front)
	{
		printf("pS or front malloc failed!!");
		exit(-1);
	}
	else
	{
		pS->rear = pS->front;
		pS->front->pNext = NULL;
	}
	return pS;
}

/*
�ж϶����Ƿ�Ϊ��
*/
bool is_empty(PQUEUE pS)
{
	if (pS->front==pS->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
���Ӻ������Ӷ�β���ӣ���ͷָ�뱣�ֲ���
*/
void en_queue(PQUEUE pS, int e)
{
	PNODE pNew = new NODE;
	if (!pNew)
	{
		printf("PNew malloc failed ");
	}
	else
	{
		pNew->data = e;
		pS->rear->pNext = pNew;
		pNew->pNext = NULL;
		pS->rear = pNew;
	}
	return;
}

/*
���Ӻ������Ӷ�ͷ���ӣ���βָ�뱣�ֲ��䣬�������һ��Ԫ�س���ʱ��
��Ҫ�Զ�βָ�����¸�ֵ��ʹ��ָ��ͷ���
*/
bool de_queue(PQUEUE pS, int* pData)
{
	if (is_empty(pS))
	{
		return false;
	}
	else
	{
		PNODE p = pS->front->pNext;
		*pData = p->data;
		pS->front->pNext = p->pNext;

		//�����Ƕ���ͷԪ�س��ӵ����������һ������£�ɾ����ͷԪ��ʱ
		//�����޸�ͷ����е�ָ�룬�������������һ��Ԫ�ر�ɾ��ʱ��
		//����βָ��Ҳ��ʧ�ˣ������Զ�βָ�����¸�ֵ��ָ��ͷ��㣩��
		if (pS->rear == p)
		{
			pS->rear = pS->front;
		}
		free(p);
	}
	return true;
}

