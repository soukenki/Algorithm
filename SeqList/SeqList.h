#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//˳���Ľṹ
typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* _a;   //ָ��̬���ٵ�����
	size_t _size;      //��ЧԪ�ظ���
	size_t _capacity;  //���������ռ�
}SeqList;

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps); //��ʼ��
void SeqListCheckCapacity(SeqList* ps); //���ռ�
void SeqListDestroy(SeqList* ps); //����

void SeqListPrint(SeqList* ps); //��ӡ
void SeqListPushBack(SeqList* ps, SLDateType x);  //β��
void SeqListPushFront(SeqList* ps, SLDateType x);  //ͷ��
void SeqListPopFront(SeqList* ps);   //ͷɾ
void SeqListPopBack(SeqList* ps);  //βɾ
 
// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);

//������
void SeqListModify(SeqList* ps, int pos, SLDateType x); //����pos��Ҫ�Ȳ���