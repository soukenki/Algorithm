#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void test1()
{
	SeqList con;
	SeqListInit(&con);//��ʼ��

	SeqListPushFront(&con, 1);//ͷ��
	SeqListPushFront(&con, 2);
	SeqListPushFront(&con, 3);
	SeqListPushFront(&con, 4);
	SeqListPushFront(&con, 5);

	SeqListPrint(&con);

	SeqListPushBack(&con, 1);//β��
	SeqListPushBack(&con, 2);
	SeqListPushBack(&con, 3);
	SeqListPushBack(&con, 4);
	SeqListPushBack(&con, 5);

	SeqListPrint(&con);

	SeqListPopFront(&con); //ͷɾ
	SeqListPopFront(&con);
	SeqListPopFront(&con);

	SeqListPrint(&con);

	SeqListPopBack(&con); //βɾ
	SeqListPopBack(&con);
	SeqListPopBack(&con);

	SeqListPrint(&con);

	SeqListInsert(&con, 2, 6); //ָ���±����
	SeqListPrint(&con);

	SeqListErase(&con, 1);//ָ���±�ɾ��
	SeqListPrint(&con);

	int ret = SeqListFind(&con, 6);//����
	if (ret != -1)
	{
		SeqListModify(&con, ret, 9);//������
	}
	SeqListPrint(&con);

	SeqListDestroy(&con); //����
	//int ret = SeqListFind(&con, SLDateType x)	// ˳������
	//SeqListInsert(&con, )//ָ������
}

int main()
{
	test1();
	return 0;
}