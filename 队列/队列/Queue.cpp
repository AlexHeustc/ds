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
	int data_de = 0;         //用来保存出队的元素值

	//创建队列并进行入队测试
	PQUEUE pS = create_queue();
	en_queue(pS, 2);
	en_queue(pS, 4);
	en_queue(pS, 6);
	traverse_queue(pS);

	//出队测试
	if (de_queue(pS, &data_de))
		printf("delete succeed,the deleted data is: %d\n", data_de);
	else
		printf("queue is empty! delete falied!\n");
	traverse_queue(pS);

	//销毁队列测试
	destroy_queue(pS);
	printf("queue destroyed!\n");
	traverse_queue(pS);

	return 0;
}

/*
创建一个空队列，队头指针和队尾指针都指向头结点，
头结点中不存放数据，只存放指针
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
判断队列是否为空
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
进队函数，从队尾进队，队头指针保持不变
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
出队函数，从队头出队，队尾指针保持不变，但当最后一个元素出队时，
需要对队尾指针重新赋值，使其指向头结点
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

		//这里是队列头元素出队的特殊情况，一般情况下，删除队头元素时
		//仅需修改头结点中的指针，但当队列中最后一个元素被删除时，
		//队列尾指针也丢失了，因此需对队尾指针重新赋值（指向头结点）。
		if (pS->rear == p)
		{
			pS->rear = pS->front;
		}
		free(p);
	}
	return true;
}

