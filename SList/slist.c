#define _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"


//��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* ret = (SListNode*)malloc(sizeof(SListNode));
	assert(ret);
	ret->data = x;
	ret->next = NULL;
	return ret;
}

//��ӡ
void SListPrint(SListNode* plist)
{
	assert(plist);
	SListNode* tail = plist;
	while (tail)
	{
		printf("%d->", tail->data);
		tail = tail->next;
	}
	printf("NULL\n");
}


// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(*pplist);
	SListNode* p = BuySListNode(x);
	SListNode* tail = *pplist;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = p;
}


// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(*pplist);
	SListNode* p = BuySListNode(x);
	p->next = *pplist;
	*pplist = p;
}

// �������βɾ
void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}

	SListNode* tail = *pplist;
	while (tail->next->next != NULL)
	{
		tail = tail->next;
	}
	free(tail->next);
	tail->next = NULL;
}

// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(*pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}

	SListNode* pre = *pplist;
	*pplist = (*pplist)->next;
	free(pre);
	pre = NULL;
}

// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);

	while (plist != NULL)
	{
		if (plist->data == x)
		{
			return plist;
		}
		plist = plist->next;
	}
	return NULL;
}

// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	
	SListNode* newnode = BuySListNode(x); //��x��ֵȥ��̬����һ���½ڵ�
	SListNode* next = pos->next;

	pos->next = newnode;
	newnode->next = next;
}

// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	if (pos->next == NULL)
	{
		printf("pos����û������\n");
		return;
	}
	else
	{
		SListNode* next = pos->next->next;
		free(pos->next);
		pos->next = next;
	}
}

// �����������
void SListDestory(SListNode* plist)
{
	assert(plist);

	while (plist) //plistΪNULLʱ����
	{
		SListNode* next = plist->next; //ѭ���ͷ�ȫ���ڵ�
		free(plist);
		plist = next;
	}
	printf("���ٳɹ�\n");
}

