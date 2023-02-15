#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void TestQueue()
{
	Queue q;
	QueueInit(&q);//初始化

	QueuePush(&q, 1);//入队
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	printf("%d ", QueueFront(&q));//取队头数据
	printf("%d ", QueueBack(&q));//取队尾数据
	printf("%d ", QueueSize(&q));//队中数据的数量
	printf("\n");
	
	QueuePop(&q);//出队
	QueuePop(&q);
	QueuePop(&q);

	printf("%d ", QueueFront(&q));//取队头数据
	printf("%d ", QueueBack(&q));//取队尾数据
	printf("%d ", QueueSize(&q));//队中数据的数量
	printf("\n");

	QueueDestroy(&q);//销毁
}

int main()
{
	TestQueue();
	return 0;
}