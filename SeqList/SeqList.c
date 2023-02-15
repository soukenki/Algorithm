#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SeqListInit(SeqList* ps) //��ʼ��
{
	assert(ps);
	ps->_a = NULL;
	ps->_size = 0;
	ps->_capacity = 0;
}

void SeqListCheckCapacity(SeqList* ps)  //��������ռ�
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		int newCapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2; //�տ�ʼ4������ÿ��*2
		SLDateType* tmp = (SLDateType*)realloc(ps->_a, newCapacity * sizeof(SLDateType));
		if (tmp == NULL)
		{
			printf("realloc : fail\n");
			exit(-1);
		}
		//����
		ps->_a = tmp;
		tmp = NULL;
		ps->_capacity = newCapacity;
	}
}

void SeqListDestroy(SeqList* ps) //����
{
	assert(ps);
	if (ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_size = 0;
		ps->_capacity = 0;
		printf("���ٳɹ�\n");
	}

}

void SeqListPrint(SeqList* ps) //��ӡ
{
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}
void SeqListPushBack(SeqList* ps, SLDateType x)  //β��
{
	assert(ps);
	SeqListInsert(ps, ps->_size, x); //�ص���
}
void SeqListPushFront(SeqList* ps, SLDateType x)  //ͷ��
{
	assert(ps);
	SeqListInsert(ps, 0, x); //�ص���

	//SeqListCheckCapacity(ps);//�������

	//if (ps->_size > 0) //Ų��ͷ����
	//{
	//	int end = ps->_size - 1;
	//	while (end >= 0)    //������β��+1��λ��
	//	{
	//		ps->_a[end + 1] = ps->_a[end];
	//		--end;
	//	}
	//}
	//ps->_sizeof++;
	//ps->_a[0]=x;

}
void SeqListPopFront(SeqList* ps)  //ͷɾ
{
	assert(ps);
	assert(ps->_size > 0);
	SeqListErase(ps, 0); //�ص���
}
void SeqListPopBack(SeqList* ps)  //βɾ
{
	assert(ps);
	assert(ps->_size > 0);
	ps->_size--; //ɾ����Ч������
}


// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->_size);

	SeqListCheckCapacity(ps);//�������

	int end = ps->_size - 1;
	while (end >= pos && end >= 0)    //������β��+1��λ��
	{
		ps->_a[end + 1] = ps->_a[end];
		--end;
	}

	ps->_a[pos] = x;
	ps->_size++;
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->_size);

	if (pos == ps->_size - 1)
	{
		ps->_size--;
		return;
	}
	else
	{
		int begin = pos + 1;  //��ֹpos=0ʱ��Խ�����
		while (begin < ps->_size)
		{
			ps->_a[begin - 1] = ps->_a[begin];
			begin++;
		}
		ps->_size--;
	}
}

// ˳������
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	for (int i = 0; i < ps->_size; ++i)
	{
		if (ps->_a[i] == x)
			return i;
	}
	return -1;
}

//������
void SeqListModify(SeqList* ps, int pos, SLDateType x) //����pos��Ҫ�Ȳ���
{
	assert(ps);
	assert(pos >= 0 && pos < ps->_size);

	ps->_a[pos] = x;
}
