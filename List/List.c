#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//�����ڵ�
LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	node->_data = x;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}

// �������������ͷ��� (��ʼ������)
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1); //ͷ�ڵ��-1
	phead->_prev = phead; //��ָ���Լ�
	phead->_next = phead;
	return phead;
}


// ˫����������
void ListDestory(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->_next;

	while (cur != phead) //ֻʣpheadʱ����
	{
		LTNode* next = cur->_next; //ѭ���ͷ�ȫ���ڵ�
		free(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;
	printf("���ٳɹ�\n");
}

// ˫�������ӡ
void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->_next;
	while (cur != phead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}


//�ж������Ƿ�Ϊ��
bool ListEmpty(LTNode* phead)
{
	assert(phead);

	return phead->_next == phead;
}


// ˫������β��
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead, x);//����

	//LTNode* newnode = BuyListNode(x);
	//LTNode* tail = phead->_prev;

	//tail->_next = newnode;
	//newnode->_prev = tail;
	//newnode->_next = phead;
	//phead->_prev = newnode;
}

// ˫������βɾ
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead)); //����Ϊ�ղż���

	ListErase(phead->_prev);

	//LTNode* tail = phead->_prev;
	//LTNode* tailPrev = tail->_prev;

	//free(tail);
	//tailPrev->_next = phead;
	//phead->_prev = tailPrev;

}
// ˫������ͷ��
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead->_next, x); //����

	//LTNode* newnode = BuyListNode(x);
	//LTNode* next = phead->_next;

	//phead->_next = newnode;
	//newnode->_next = next;
	//next->_prev = newnode;
	//newnode->_prev = phead;

}
// ˫������ͷɾ
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));//����Ϊ�ղż���
	ListErase(phead->_next); //����
}

// ˫���������
LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->_next;

	while (cur != phead)
	{
		if (cur->_data == x) 
			return cur; //�ҵ���
		else
			cur = cur->_next;
	}
	
	return NULL; //�Ҳ���
}
// ˫��������pos��ǰ����в���
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->_prev;
	LTNode* newnode = BuyListNode(x);

	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;

}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prve = pos->_prev;
	LTNode* next = pos->_next;

	prve->_next = next;
	next->_prev = prve;
	free(pos);
}
