#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"
#include <time.h>

void TestHeap()
{
	HP hp;
	HeapInit(&hp);
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);

	HeapPush(&hp, 10);
	HeapPrint(&hp);
}
void TeatHeapSort()
{
	//�����ӡ -- С��
	//�����ӡ -- ���
	HP hp;
	HeapInit(&hp);
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		HeapPush(&hp, a[i]);
	}

	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");
}
//void HeapSort(int* a ,int n)
//{
//	//�������� -- С��
//	//�������� -- ���
//	HP hp;
//	HeapInit(&hp);
//	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
//	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	int i = 0;
//	while (!HeapEmpty(&hp))
//	{
//		a[i++] = HeapTop(&hp);
//		HeapPop(&hp);
//	}
//	HeapDestroy(&hp);
//}
void HeapSort(int* a, int n) //O(NlogN)
{
	////���ѵķ�ʽ1��O(N)
	//for (int i = 1; i < n; ++i)
	//{
	//	AdjustUp(a, i);  //�������ϵ�����������
	//}

	//���ѵķ�ʽ2��O(logN)
	//�ӵ�����һ����Ҷ�ӽڵ㿪ʼ��
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);  //�������µ�����������
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}
void PrintTopK(int* a, int n, int k)//��ӡN������K��������
{
	//1.����--��a�е�ǰk��Ԫ�ؽ� С��
	int* KMinHeap = (int*)malloc(sizeof(int) * k);
	assert(KMinHeap);
	for (int i = 0; i < k; ++i)
	{
		KMinHeap[i] = a[i];
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(KMinHeap, k, i);  //���µ�����������
	}

	//2.��ʣ��n-k��Ԫ��������Ѷ���Ԫ�رȽϣ��滻�Ѷ����ݽ���
	for (int j = k; j < n; ++j)
	{
		if (a[j] > KMinHeap[0])
		{
			KMinHeap[0] = a[j]; //�滻
			AdjustDwon(KMinHeap, k, 0); //���µ���
		}
	}
	//��ӡ
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", KMinHeap[i]);
	}
	printf("\n");
	//����
	free(KMinHeap);
	KMinHeap = NULL;
}
void TestTopk() //����PrintTopK
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n); 
	srand(time(0));
	for (size_t i = 0; i < n; ++i) 
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10; 
	PrintTopK(a, n, 10);
}
int main()
{
	//TestHeap();
	//TeatHeapSort();
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	//HeapSort(a, sizeof(a)/sizeof(a[0]));
	TestTopk();
	return 0;
}