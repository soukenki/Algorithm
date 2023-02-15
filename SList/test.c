#define _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"

void SListTest1()
{
	SListNode* plist = BuySListNode(1);
	SListPushBack(&plist, 2);//β��
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPushFront(&plist, 9);//ͷ��
	SListPushFront(&plist, 8);
	SListPushFront(&plist, 7);
	SListPrint(plist);

	SListPopBack(&plist);//βɾ
	SListPrint(plist);

	SListPopFront(&plist);//ͷɾ
	SListPrint(plist);


	SListNode* pos = SListFind(plist, 9); //����
	if (pos != NULL)
	{
		SListInsertAfter(pos, 6);//��posλ��֮�����x 9�������6
		SListPrint(plist);
	}

	pos = SListFind(plist, 1); //����
	if (pos != NULL)
	{
		SListEraseAfter(pos);//ɾ��posλ��֮���ֵ 1����ɾ��2
		SListPrint(plist);
	}
	SListDestory(plist);//����
}


int main()
{
	SListTest1();

	return 0;
}
