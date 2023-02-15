#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void test1()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 5);//Î²²å
	ListPushBack(plist, 6);
	ListPushBack(plist, 7);
	ListPrint(plist);

	ListPushFront(plist, 3);//Í·²å
	ListPushFront(plist, 2);
	ListPushFront(plist, 1);
	ListPrint(plist);

	ListPopBack(plist);//Î²É¾
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPopFront(plist);//Í·É¾
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);

	LTNode* pos = ListFind(plist, 5);//²éÕÒ
	pos->_data = 100000;
	ListPrint(plist);

	ListDestory(plist);//Ïú»Ù
}
int main()
{
	test1();
	return 0;
}