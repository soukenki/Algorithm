#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//堆结构
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}HP;


void HeapInit(HP* php);  //初始化
void HeapDestroy(HP* php);  //销毁
void HeapPrint(HP* php); //打印堆
void Swap(HPDataType* p1, HPDataType* p2); //交换
void AdjustUp(HPDataType* a, int child); //向上调整
void AdjustDwon(HPDataType* a, int size, int parent); //向下调整
void HeapPush(HP* php, HPDataType x);  //入堆
void HeadPop(HP* php);  //出堆
HPDataType HeapTop(HP* php);  //取堆顶数据
bool HeapEmpty(HP* php);  //判断堆是否为空
int HeapSize(HP* php);   //计算堆内数据的数量
