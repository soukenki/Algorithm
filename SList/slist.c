#define _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"


//动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* ret = (SListNode*)malloc(sizeof(SListNode));
	assert(ret);
	ret->data = x;
	ret->next = NULL;
	return ret;
}

//打印
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


// 单链表尾插
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


// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(*pplist);
	SListNode* p = BuySListNode(x);
	p->next = *pplist;
	*pplist = p;
}

// 单链表的尾删
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

// 单链表头删
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

// 单链表查找
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

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	
	SListNode* newnode = BuySListNode(x); //用x的值去动态申请一个新节点
	SListNode* next = pos->next;

	pos->next = newnode;
	newnode->next = next;
}

// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	if (pos->next == NULL)
	{
		printf("pos后面没有数据\n");
		return;
	}
	else
	{
		SListNode* next = pos->next->next;
		free(pos->next);
		pos->next = next;
	}
}

// 单链表的销毁
void SListDestory(SListNode* plist)
{
	assert(plist);

	while (plist) //plist为NULL时结束
	{
		SListNode* next = plist->next; //循环释放全部节点
		free(plist);
		plist = next;
	}
	printf("销毁成功\n");
}

