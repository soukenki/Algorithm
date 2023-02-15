#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapInit(HP* php)  //��ʼ��
{
	assert(php);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}

void HeapDestroy(HP* php)  //����
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}

void HeapPrint(HP* php)  //��ӡ��
{
	assert(php);
	for (int i = 0; i < php->_size; ++i)
	{
		printf("%d ", php->_a[i]);
	}
	printf("\n");
}

void Swap(HPDataType* p1, HPDataType* p2) //����
{
	assert(p1 && p2);

	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int child) //���ϵ���
{
	int parent = (child - 1) / 2; //���׽ڵ���±�
	while (child > 0)  //�����±� >0
	{
		//if (a[child] < a[parent])  //����С�ڸ��� (С��)
		if (a[child] < a[parent])  //����С�ڸ��� (���)
		{
			Swap(&a[child], &a[parent]);//����
			child = parent;           //���º��Ӻ͸��׵��±�
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)  //���
{
	assert(php);
	if (php->_size == php->_capacity)
	{
		//����
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

	php->_a[php->_size] = x;  //����ѵ����ݣ������������һ��
	php->_size++;

	AdjustUp(php->_a, php->_size - 1); //������ �� ���һ�����ݵ��±� ���д���

}

void AdjustDwon(HPDataType* a, int size, int parent) //���µ���
{
	//�ҵ����Һ����У�С���Ǹ����н�����ֱ��Ҷ�ӻ��ߺ��Ӷ��ȸ���С(��)
	int child = parent * 2 + 1; //����

	while (child < size) //�߽�
	{
		if (child + 1 < size && a[child + 1] > a[child]) //���Һ��ӱȴ�С
			++child;
		if (a[child] > a[parent]) //��С(��)�ĺ��Ӹ����ױȽ�
		{
			Swap(&a[child], &a[parent]); //����
			parent = child;
			child = parent * 2 + 1;  //���¸��׺ͺ��ӵĽڵ�
		}
		else
			break;
	}
}


void HeapPop(HP* php)  //����
{
	assert(php);
	assert(php->_size > 0);

	Swap(&(php->_a[0]), &(php->_a[php->_size - 1])); //����ͷ��β������
	php->_size--; //ɾ������������һ������

	//���µ���
	AdjustDwon(php->_a, php->_size, 0);  //���飬��С�����µ�������ʼλ�õ��±�
}

HPDataType HeapTop(HP* php)  //ȡ�Ѷ�����
{
	assert(php);
	assert(php->_size > 0);
	return php->_a[0];
}

bool HeapEmpty(HP* php)  //�ж϶��Ƿ�Ϊ��
{
	assert(php);
	return php->_size == 0;
}

int HeapSize(HP* php)   //����������ݵ�����
{
	assert(php);
	return php->_size;
}



