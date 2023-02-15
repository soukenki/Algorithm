#define _CRT_SECURE_NO_WARNINGS 1

#include "AVLTree.h"

void TestAVLTree1()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4,2,6,1,3,5,15,7,16,14 };  // ����˫��ƽ�����ӵ���
	AVLTree<int, int> t1;
	for (auto e : a)
	{
		t1.Insert(make_pair(e, e));
	}

	t1.InOrder();
	cout << "IsBalance=" << t1.IsBalance() << endl; 
}
void TestAVLTree2()
{
	size_t N = 10000;
	srand(time(0));   // ʹrand()����һ��ʱ����������
	AVLTree<int, int> t1;
	for (size_t i = 0; i < N; ++i)
	{
		int x = rand();
		/*
		if (x == ??)
			int u = 1;  // �ϵ���
		*/
		t1.Insert(make_pair(x, i));
		/*	bool ret = t1.IsBalance();  // �����ϵ��д�
			if (ret == false)
			{
				int u = 1;
			}
			else
			{
				cout << "Insert:" << x << " IsBalance:" << ret << endl;
			}
// 1. �Ȱ�srand����ע�͵����������ߣ�ÿ�ε��Ե�ֵ����䡣
// 2. ͨ�����ԣ��ҵ��Ǹ������xֵ��Ȼ������x����֮ǰ��һ��if(x == ??)�����жϵ㡣
// 3. ͨ��xֵ�ĵ��β������̣����в��ұ���λ�á�
		*/
	}
	cout << "IsBalance:" << t1.IsBalance() << endl;
}
int main()
{
	TestAVLTree1();
	TestAVLTree2();

	return 0;
}