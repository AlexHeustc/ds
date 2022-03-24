#include<stdio.h>
#include<stdlib.h>
#include "data_structure.h"


/*
创建一个槽数为n的哈希表
*/
HashTable create_HashTable(int n)
{
	int i;
	HashTable hashtable = new HashNode;
	if (! hashtable)
	{
		printf("hashtable malloc faild,program exit...");
		exit(-1);
	}

	//将哈希表置空
	for (int i = 0; i < n; i++)
	{
		hashtable[i].first = NULL;
	}
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
	pNode pNew = new Node;
	if (!pNew)
	{
		printf("malloc failed,prom exited");
		exit(-1);
	}
}
