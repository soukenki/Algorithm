#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void test1()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 5);//β��
	ListPushBack(plist, 6);
	ListPushBack(plist, 7);
	ListPrint(plist);

	ListPushFront(plist, 3);//ͷ��
	ListPushFront(plist, 2);
	ListPushFront(plist, 1);
	ListPrint(plist);

	ListPopBack(plist);//βɾ
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPopFront(plist);//ͷɾ
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);

	LTNode* pos = ListFind(plist, 5);//����
	pos->_data = 100000;
	ListPrint(plist);

	ListDestory(plist);//����
}
int main()
{
	test1();
	return 0;
}