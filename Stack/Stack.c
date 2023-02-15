#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(ST* ps) //初始化
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackDestory(ST* ps) //销毁
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackPush(ST* ps, STDataType x) //插入
{
	assert(ps);

	if (ps->_top == ps->_capacity)  //扩容
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

void StackPop(ST* ps)  //删除
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->_top--;
}

STDataType StackTop(ST* ps) //获取栈顶数据
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->_a[ps->_top - 1];
}

bool StackEmpty(ST* ps) //判断是否为空
{
	assert(ps);
	return ps->_top == 0;
}

int StackSize(ST* ps)   //获取栈内数据的数量
{
	assert(ps);
	return ps->_top;
}








