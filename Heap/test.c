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
	//升序打印 -- 小堆
	//降序打印 -- 大堆
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
//	//升序排序 -- 小堆
//	//降序排序 -- 大堆
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
	////建堆的方式1：O(N)
	//for (int i = 1; i < n; ++i)
	//{
	//	AdjustUp(a, i);  //利用向上调整进行排序
	//}

	//建堆的方式2：O(logN)
	//从倒数第一个非叶子节点开始调
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);  //利用向下调整进行排序
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}
void PrintTopK(int* a, int n, int k)//打印N个数中K个最大的数
{
	//1.建堆--用a中的前k个元素建 小堆
	int* KMinHeap = (int*)malloc(sizeof(int) * k);
	assert(KMinHeap);
	for (int i = 0; i < k; ++i)
	{
		KMinHeap[i] = a[i];
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(KMinHeap, k, i);  //向下调整进行排序
	}

	//2.将剩余n-k个元素依次与堆顶的元素比较，替换堆顶数据进堆
	for (int j = k; j < n; ++j)
	{
		if (a[j] > KMinHeap[0])
		{
			KMinHeap[0] = a[j]; //替换
			AdjustDwon(KMinHeap, k, 0); //向下调整
		}
	}
	//打印
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", KMinHeap[i]);
	}
	printf("\n");
	//销毁
	free(KMinHeap);
	KMinHeap = NULL;
}
void TestTopk() //测试PrintTopK
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