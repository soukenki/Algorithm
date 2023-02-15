#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 带头+双向+循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}LTNode;

//新增节点
LTNode* BuyListNode(LTDataType);
// 创建返回链表的头结点.(初始化链表)
LTNode* ListInit();
// 双向链表销毁
void ListDestory(LTNode* phead);
// 双向链表打印
void ListPrint(LTNode* phead);

//判断链表是否为空
bool ListEmpty(LTNode* phead);
// 双向链表尾插
void ListPushBack(LTNode* phead, LTDataType x);
// 双向链表尾删
void ListPopBack(LTNode* phead);
// 双向链表头插
void ListPushFront(LTNode* phead, LTDataType x);
// 双向链表头删
void ListPopFront(LTNode* phead);
// 双向链表查找
LTNode* ListFind(LTNode* phead, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(LTNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
void ListErase(LTNode* pos);
