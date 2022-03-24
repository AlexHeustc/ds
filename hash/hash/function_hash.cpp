#include<stdio.h>
#include<stdlib.h>
#include "data_structure.h"


/*
����һ������Ϊn�Ĺ�ϣ��
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

	//����ϣ���ÿ�
	for (int i = 0; i < n; i++)
	{
		hashtable[i].first = NULL;
	}
	return hashtable;
}

/*
�ڹ�ϣ���в�������data�����ҳɹ��򷵻��������е�λ�ã�
���Ҳ��ɹ��򷵻�NULL�����й�ϣ����ΪH(key)=key%M
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
���ϣ���в�������data�����data�Ѵ��ڣ��򷵻�fasle��
���򣬲����Ӧ�������󲢷���true�����й�ϣ����ΪH(key)=key%M
*/
bool insert_HashTable(HashTable hashtable, ElemType data)
{
	//����Ѿ����ڣ�����false
	if (search_HashTable(hashtable, data)) return false;

	//����Ϊdata����ռ�
	pNode pNew = new Node;
	if (!pNew)
	{
		printf("malloc failed,prom exited");
		exit(-1);
	}
}
