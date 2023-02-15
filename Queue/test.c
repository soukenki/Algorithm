#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void TestQueue()
{
	Queue q;
	QueueInit(&q);//��ʼ��

	QueuePush(&q, 1);//���
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	printf("%d ", QueueFront(&q));//ȡ��ͷ����
	printf("%d ", QueueBack(&q));//ȡ��β����
	printf("%d ", QueueSize(&q));//�������ݵ�����
	printf("\n");
	
	QueuePop(&q);//����
	QueuePop(&q);
	QueuePop(&q);

	printf("%d ", QueueFront(&q));//ȡ��ͷ����
	printf("%d ", QueueBack(&q));//ȡ��β����
	printf("%d ", QueueSize(&q));//�������ݵ�����
	printf("\n");

	QueueDestroy(&q);//����
}

int main()
{
	TestQueue();
	return 0;
}