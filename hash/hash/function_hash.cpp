#include<stdio.h>
#include<stdlib.h>
#include "data_structure.h"


/*
创建一个槽数为n的哈希表
*/
HashTable create_HashTable(int n)
{
	int i;
	HashTable hashtable = (HashTable)malloc(n * sizeof(HashNode));
	if (!hashtable)
	{
		printf("hashtable malloc faild,program exit...");
		exit(-1);
	}

	//将哈希表置空
	for (i = 0; i < n; i++)
		hashtable[i].first = NULL;
	//	memset(hashtable,0,sizeof(hashtable));

	return hashtable;
}

/*
在哈希表中查找数据data，查找成功则返回在链表中的位置，
查找不成功则返回NULL，其中哈希函数为H(key)=key%M
*/

pNode search_HashTable(HashTable hashtable, ElemType data)
{
	if (!hashtable)
	{
		return NULL;
	}

	pNode pcur = hashtable[data % M].first;
	while (pcur && pcur->data != data)
	{
		pcur = pcur->next;
	}

	return pcur;
}

/*
向哈希表中插入数据data，如果data已存在，则返回fasle，
否则，插入对应链表的最后并返回true，其中哈希函数为H(key)=key%M
*/
bool insert_HashTable(HashTable hashtable, ElemType data)
{
	//如果已经存在，返回false
	if (search_HashTable(hashtable, data)) return false;

	//否则为data分配空间
	pNode pNew = (pNode)malloc(sizeof(Node));
	if (!pNew)
	{
		printf("malloc failed,prom exited");
		exit(-1);
	}

	pNew->data = data;
	pNew->next = NULL;

	//将节点插入到对应链表的最后
	pNode pcur = hashtable[data % M].first;
	if (!pcur)
	{
		hashtable[data % M].first = pNew;
	}
	else
	{
		while (pcur->next)
		{
			pcur = pcur->next;
		}
		pcur->next = pNew;
	}
	return true;
}

/*
从哈希表中删除数据data，如果data不存在，则返回fasle，
否则，删除之并返回true，其中哈希函数为H(key)=key%M
*/
bool delete_HashTable(HashTable hashtable,ElemType data)
{
	//如果没查找到，返回false
	if(!search_HashTable(hashtable,data))
		return false;
	//否则，一定存在，找到删除之
	pNode pCur = hashtable[data%M].first;
	pNode pPre = pCur;	//被删节点的前一个节点,初始值与pCur相同
	if(pCur->data == data)	//被删节点是链表的第一个节点的情况
		hashtable[data%M].first = pCur->next;
	else
	{	//被删节点不是第一个节点的情况
		while(pCur && pCur->data != data)
		{
			pPre = pCur;
			pCur = pCur->next;
		}
		pPre->next = pCur->next;
	}
	free(pCur);
	pCur = 0;
	return true;
}

/*
销毁槽数为n的哈希表
*/
void destroy_HashTable(HashTable hashtable, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		pNode pcur = hashtable[i].first;
		pNode pdel = NULL;
		while (pcur)
		{
			pdel = pcur;
			pcur = pcur->next;
			delete pdel;
			pdel = 0;
		}
	}
	delete hashtable;
	hashtable = 0;
}
