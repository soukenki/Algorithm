#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>    

typedef int SLTDateType;

//�����ṹ��
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

//��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
// �������ӡ
void SListPrint(SListNode* plist);

// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x);
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);

// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);

// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);

// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x);

// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos);

// �����������
void SListDestory(SListNode* plist);

