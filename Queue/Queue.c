#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void QueueInit(Queue* pq)  //��ʼ��
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}

void QueueDestroy(Queue* pq)  //����
{
	assert(pq);
	QNode* cur = pq->_head;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}

	pq->_head = pq->_tail = NULL;
}

void QueuePush(Queue* pq, QDataType x) //���
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode)); //�½�һ���ڵ�
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->_data = x;
	newnode->_next = NULL;

	//���
	if (pq->_tail == NULL)
	{
		pq->_head = pq->_tail = newnode; 
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}

void QueuePop(Queue* pq)  //����
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->_head->_next == NULL) //ʣ���һ���ڵ�ʱ
	{
		free(pq->_head);
		pq->_head = pq->_tail = NULL;
	}
	else  //�ж���ڵ�ʱ
	{
		Queue* next = pq->_head->_next;
		free(pq->_head);
		pq->_head = next;
	}
}

QDataType QueueFront(Queue* pq)  //ȡ��ͷ����
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->_head->_data;
}

QDataType QueueBack(Queue* pq)  //ȡ��β����
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->_tail->_data;
}

bool QueueEmpty(Queue* pq)  //�ж��Ƿ�Ϊ��
{
	assert(pq);
	return pq->_head == NULL;
}

int QueueSize(Queue* pq) //�������ݵ�����
{
	assert(pq);
	QNode* cur = pq->_head;
	int size = 0;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}