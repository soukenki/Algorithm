#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}LTNode;

//�����ڵ�
LTNode* BuyListNode(LTDataType);
// �������������ͷ���.(��ʼ������)
LTNode* ListInit();
// ˫����������
void ListDestory(LTNode* phead);
// ˫�������ӡ
void ListPrint(LTNode* phead);

//�ж������Ƿ�Ϊ��
bool ListEmpty(LTNode* phead);
// ˫������β��
void ListPushBack(LTNode* phead, LTDataType x);
// ˫������βɾ
void ListPopBack(LTNode* phead);
// ˫������ͷ��
void ListPushFront(LTNode* phead, LTDataType x);
// ˫������ͷɾ
void ListPopFront(LTNode* phead);
// ˫���������
LTNode* ListFind(LTNode* phead, LTDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(LTNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(LTNode* pos);
