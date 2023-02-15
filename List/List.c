#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//新增节点
LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	node->_data = x;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}

// 创建返回链表的头结点 (初始化链表)
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1); //头节点放-1
	phead->_prev = phead; //都指向自己
	phead->_next = phead;
	return phead;
}


// 双向链表销毁
void ListDestory(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->_next;

	while (cur != phead) //只剩phead时结束
	{
		LTNode* next = cur->_next; //循环释放全部节点
		free(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;
	printf("销毁成功\n");
}

// 双向链表打印
void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->_next;
	while (cur != phead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}


//判断链表是否为空
bool ListEmpty(LTNode* phead)
{
	assert(phead);

	return phead->_next == phead;
}


// 双向链表尾插
void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead, x);//复用

	//LTNode* newnode = BuyListNode(x);
	//LTNode* tail = phead->_prev;

	//tail->_next = newnode;
	//newnode->_prev = tail;
	//newnode->_next = phead;
	//phead->_prev = newnode;
}

// 双向链表尾删
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead)); //链表不为空才继续

	ListErase(phead->_prev);

	//LTNode* tail = phead->_prev;
	//LTNode* tailPrev = tail->_prev;

	//free(tail);
	//tailPrev->_next = phead;
	//phead->_prev = tailPrev;

}
// 双向链表头插
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	ListInsert(phead->_next, x); //复用

	//LTNode* newnode = BuyListNode(x);
	//LTNode* next = phead->_next;

	//phead->_next = newnode;
	//newnode->_next = next;
	//next->_prev = newnode;
	//newnode->_prev = phead;

}
// 双向链表头删
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));//链表不为空才继续
	ListErase(phead->_next); //复用
}

// 双向链表查找
LTNode* ListFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* cur = phead->_next;

	while (cur != phead)
	{
		if (cur->_data == x) 
			return cur; //找到了
		else
			cur = cur->_next;
	}
	
	return NULL; //找不到
}
// 双向链表在pos的前面进行插入
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->_prev;
	LTNode* newnode = BuyListNode(x);

	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;

}
// 双向链表删除pos位置的节点
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prve = pos->_prev;
	LTNode* next = pos->_next;

	prve->_next = next;
	next->_prev = prve;
	free(pos);
}
