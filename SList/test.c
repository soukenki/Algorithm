#define _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"

void SListTest1()
{
	SListNode* plist = BuySListNode(1);
	SListPushBack(&plist, 2);//尾增
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPushFront(&plist, 9);//头增
	SListPushFront(&plist, 8);
	SListPushFront(&plist, 7);
	SListPrint(plist);

	SListPopBack(&plist);//尾删
	SListPrint(plist);

	SListPopFront(&plist);//头删
	SListPrint(plist);


	SListNode* pos = SListFind(plist, 9); //查找
	if (pos != NULL)
	{
		SListInsertAfter(pos, 6);//在pos位置之后插入x 9后面插入6
		SListPrint(plist);
	}

	pos = SListFind(plist, 1); //查找
	if (pos != NULL)
	{
		SListEraseAfter(pos);//删除pos位置之后的值 1后面删除2
		SListPrint(plist);
	}
	SListDestory(plist);//销毁
}


int main()
{
	SListTest1();

	return 0;
}
