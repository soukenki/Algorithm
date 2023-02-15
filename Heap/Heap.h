#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//�ѽṹ
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}HP;


void HeapInit(HP* php);  //��ʼ��
void HeapDestroy(HP* php);  //����
void HeapPrint(HP* php); //��ӡ��
void Swap(HPDataType* p1, HPDataType* p2); //����
void AdjustUp(HPDataType* a, int child); //���ϵ���
void AdjustDwon(HPDataType* a, int size, int parent); //���µ���
void HeapPush(HP* php, HPDataType x);  //���
void HeadPop(HP* php);  //����
HPDataType HeapTop(HP* php);  //ȡ�Ѷ�����
bool HeapEmpty(HP* php);  //�ж϶��Ƿ�Ϊ��
int HeapSize(HP* php);   //����������ݵ�����
