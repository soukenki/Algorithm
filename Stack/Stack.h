#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

//栈结构（动态）
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;      //栈顶
	int _capacity;   //空间
}ST;

void StackInit(ST* ps);  //初始化
void StackDestory(ST* ps);  //销毁

void StackPush(ST* ps, STDataType x); //插入
void StackPop(ST* ps);  //删除

STDataType StackTop(ST* ps); //获取栈顶数据
bool StackEmpty(ST* ps);  //判断是否为空
int StackSize(ST* ps);   //获取栈内数据的数量
