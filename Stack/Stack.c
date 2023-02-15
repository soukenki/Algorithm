#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(ST* ps) //��ʼ��
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackDestory(ST* ps) //����
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackPush(ST* ps, STDataType x) //����
{
	assert(ps);

	if (ps->_top == ps->_capacity)  //����
	{
		int newCapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->_a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		ps->_a = tmp;
		ps->_capacity = newCapacity;
	}

	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(ST* ps)  //ɾ��
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->_top--;
}

STDataType StackTop(ST* ps) //��ȡջ������
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->_a[ps->_top - 1];
}

bool StackEmpty(ST* ps) //�ж��Ƿ�Ϊ��
{
	assert(ps);
	return ps->_top == 0;
}

int StackSize(ST* ps)   //��ȡջ�����ݵ�����
{
	assert(ps);
	return ps->_top;
}








