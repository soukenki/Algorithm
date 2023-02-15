#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void test1()
{
	SeqList con;
	SeqListInit(&con);//初始化

	SeqListPushFront(&con, 1);//头增
	SeqListPushFront(&con, 2);
	SeqListPushFront(&con, 3);
	SeqListPushFront(&con, 4);
	SeqListPushFront(&con, 5);

	SeqListPrint(&con);

	SeqListPushBack(&con, 1);//尾增
	SeqListPushBack(&con, 2);
	SeqListPushBack(&con, 3);
	SeqListPushBack(&con, 4);
	SeqListPushBack(&con, 5);

	SeqListPrint(&con);

	SeqListPopFront(&con); //头删
	SeqListPopFront(&con);
	SeqListPopFront(&con);

	SeqListPrint(&con);

	SeqListPopBack(&con); //尾删
	SeqListPopBack(&con);
	SeqListPopBack(&con);

	SeqListPrint(&con);

	SeqListInsert(&con, 2, 6); //指定下标插入
	SeqListPrint(&con);

	SeqListErase(&con, 1);//指定下标删除
	SeqListPrint(&con);

	int ret = SeqListFind(&con, 6);//查找
	if (ret != -1)
	{
		SeqListModify(&con, ret, 9);//改数据
	}
	SeqListPrint(&con);

	SeqListDestroy(&con); //销毁
	//int ret = SeqListFind(&con, SLDateType x)	// 顺序表查找
	//SeqListInsert(&con, )//指定插入
}

int main()
{
	test1();
	return 0;
}