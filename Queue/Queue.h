#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//���нṹ
typedef int QDataType;
typedef struct QueueNode //һ���ڵ�
{
	struct QueueNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue  //�ṹ��Ƕ��
{
	//int size; //Ҳ���������ｨsize����¼��С
	QNode* _head;
	QNode* _tail;
}Queue;

void QueueInit(Queue* pq);  //��ʼ��
void QueueDestroy(Queue* pq);  //����
void QueuePush(Queue* pq, QDataType x); //���
void QueuePop(Queue* pq);  //����
QDataType QueueFront(Queue* pq);  //ȡ��ͷ����
QDataType QueueBack(Queue* pq);  //ȡ��β����
bool QueueEmpty(Queue* pq);  //�ж��Ƿ�Ϊ��
int QueueSize(Queue* pq); //�������ݵ�����

 