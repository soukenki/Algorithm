#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//顺序表的结构
typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* _a;   //指向动态开辟的数组
	size_t _size;      //有效元素个数
	size_t _capacity;  //数组容量空间
}SeqList;

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps); //初始化
void SeqListCheckCapacity(SeqList* ps); //检查空间
void SeqListDestroy(SeqList* ps); //销毁

void SeqListPrint(SeqList* ps); //打印
void SeqListPushBack(SeqList* ps, SLDateType x);  //尾增
void SeqListPushFront(SeqList* ps, SLDateType x);  //头增
void SeqListPopFront(SeqList* ps);   //头删
void SeqListPopBack(SeqList* ps);  //尾删
 
// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);

//改数据
void SeqListModify(SeqList* ps, int pos, SLDateType x); //参数pos需要先查找