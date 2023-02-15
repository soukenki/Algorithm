#define _CRT_SECURE_NO_WARNINGS 1

#include "AVLTree.h"

void TestAVLTree1()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4,2,6,1,3,5,15,7,16,14 };  // 测试双旋平衡因子调节
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
	srand(time(0));   // 使rand()返回一个时间戳的随机数
	AVLTree<int, int> t1;
	for (size_t i = 0; i < N; ++i)
	{
		int x = rand();
		/*
		if (x == ??)
			int u = 1;  // 断点用
		*/
		t1.Insert(make_pair(x, i));
		/*	bool ret = t1.IsBalance();  // 条件断点判错
			if (ret == false)
			{
				int u = 1;
			}
			else
			{
				cout << "Insert:" << x << " IsBalance:" << ret << endl;
			}
// 1. 先把srand函数注释掉，让它闭线，每次调试的值不会变。
// 2. 通过调试，找到那个报错的x值，然后再在x插入之前加一个if(x == ??)语句进行断点。
// 3. 通过x值的单次插入流程，进行查找报错位置。
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