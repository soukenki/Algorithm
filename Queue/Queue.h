#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

//队列结构
typedef int QDataType;
typedef struct QueueNode //一个节点
{
	struct QueueNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue  //结构体嵌套
{
	//int size; //也可以在这里建size来记录大小
	QNode* _head;
	QNode* _tail;
}Queue;

void QueueInit(Queue* pq);  //初始化
void QueueDestroy(Queue* pq);  //销毁
void QueuePush(Queue* pq, QDataType x); //入队
void QueuePop(Queue* pq);  //出队
QDataType QueueFront(Queue* pq);  //取队头数据
QDataType QueueBack(Queue* pq);  //取队尾数据
bool QueueEmpty(Queue* pq);  //判断是否为空
int QueueSize(Queue* pq); //队中数据的数量

 