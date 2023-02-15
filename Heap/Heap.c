#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapInit(HP* php)  //初始化
{
	assert(php);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}

void HeapDestroy(HP* php)  //销毁
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}

void HeapPrint(HP* php)  //打印堆
{
	assert(php);
	for (int i = 0; i < php->_size; ++i)
	{
		printf("%d ", php->_a[i]);
	}
	printf("\n");
}

void Swap(HPDataType* p1, HPDataType* p2) //交换
{
	assert(p1 && p2);

	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int child) //向上调整
{
	int parent = (child - 1) / 2; //父亲节点的下标
	while (child > 0)  //孩子下标 >0
	{
		//if (a[child] < a[parent])  //孩子小于父亲 (小堆)
		if (a[child] < a[parent])  //孩子小于父亲 (大堆)
		{
			Swap(&a[child], &a[parent]);//交换
			child = parent;           //更新孩子和父亲的下标
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)  //入堆
{
	assert(php);
	if (php->_size == php->_capacity)
	{
		//扩容
		int newCapacity = php->_capacity == 0 ? 4 : php->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->_a = tmp;
		php->_capacity = newCapacity;
	}

	php->_a[php->_size] = x;  //新入堆的数据，放在数组最后一个
	php->_size++;

	AdjustUp(php->_a, php->_size - 1); //以数组 和 最后一个数据的下标 进行传参

}

void AdjustDwon(HPDataType* a, int size, int parent) //向下调整
{
	//找到左右孩子中，小的那个进行交换，直到叶子或者孩子都比父亲小(大)
	int child = parent * 2 + 1; //左孩子

	while (child < size) //边界
	{
		if (child + 1 < size && a[child + 1] > a[child]) //左右孩子比大小
			++child;
		if (a[child] > a[parent]) //更小(大)的孩子跟父亲比较
		{
			Swap(&a[child], &a[parent]); //交换
			parent = child;
			child = parent * 2 + 1;  //更新父亲和孩子的节点
		}
		else
			break;
	}
}


void HeapPop(HP* php)  //出堆
{
	assert(php);
	assert(php->_size > 0);

	Swap(&(php->_a[0]), &(php->_a[php->_size - 1])); //交换头和尾的数据
	php->_size--; //删除交换后的最后一个数据

	//向下调整
	AdjustDwon(php->_a, php->_size, 0);  //数组，大小，向下调整的起始位置的下标
}

HPDataType HeapTop(HP* php)  //取堆顶数据
{
	assert(php);
	assert(php->_size > 0);
	return php->_a[0];
}

bool HeapEmpty(HP* php)  //判断堆是否为空
{
	assert(php);
	return php->_size == 0;
}

int HeapSize(HP* php)   //计算堆内数据的数量
{
	assert(php);
	return php->_size;
}



