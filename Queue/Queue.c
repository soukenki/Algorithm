#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void QueueInit(Queue* pq)  //初始化
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}

void QueueDestroy(Queue* pq)  //销毁
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

void QueuePush(Queue* pq, QDataType x) //入队
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode)); //新建一个节点
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->_data = x;
	newnode->_next = NULL;

	//入队
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

void QueuePop(Queue* pq)  //出队
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->_head->_next == NULL) //剩最后一个节点时
	{
		free(pq->_head);
		pq->_head = pq->_tail = NULL;
	}
	else  //有多个节点时
	{
		Queue* next = pq->_head->_next;
		free(pq->_head);
		pq->_head = next;
	}
}

QDataType QueueFront(Queue* pq)  //取队头数据
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->_head->_data;
}

QDataType QueueBack(Queue* pq)  //取队尾数据
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->_tail->_data;
}

bool QueueEmpty(Queue* pq)  //判断是否为空
{
	assert(pq);
	return pq->_head == NULL;
}

int QueueSize(Queue* pq) //队中数据的数量
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