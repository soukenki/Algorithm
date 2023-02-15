#define _CRT_SECURE_NO_WARNINGS 1


#include "BinarySearchTree.h"

void TestBSTree1() // test循环版
{
	Key::BSTree<int> t;
	int a[] = { 8, 3, 7, 2, 5, 6, 6,0,-1 };
	for (auto e : a)
	{
		t.Insert(e);
	}

	// 排序 + 去重
	t.InOrder();

	t.Erase(3);
	t.InOrder();

	t.Erase(6);
	t.InOrder();

	for (auto e : a)
	{
		t.Erase(e);
		t.InOrder();
	}
}

void TestBSTree2() // test递归版
{
	Key::BSTree<int> t;
	int a[] = { 8, 3, 7, 2, 5, 6, 6,0,-1 };
	for (auto e : a)
	{
		t.Insert(e);
	}


	// 排序 + 去重
	t.InOrder();

	t.EraseR(0);
	t.InOrder();

	t.EraseR(-1);
	t.InOrder();

	for (auto e : a)
	{
		t.EraseR(e);
		t.InOrder();
	}
}

void TestBSTree3() // 模拟电子词典
{
	KeyValue::BSTree<string, string> dict;
	dict.Insert("sort", "排序");
	dict.Insert("left", "左边");
	dict.Insert("right", "右边");
	dict.Insert("string", "字符串");
	dict.Insert("insert", "插入");
	string str;
	while (cin >> str)  // 写入IO流 Ctrl+z+回车 退出
	{
		KeyValue::BSTreeNode<string, string>* ret = dict.Find(str);
		if (ret)
		{
			cout << "对应的中文:" << ret->_value << endl;
		}
		else
		{
			cout << "对应的中文->无此单词" << endl;
		}
	}
}

void TestBSTree4() // 计算出现过的水果数
{
	string arr[] = { "香蕉", "苹果", "香蕉", "草莓", "香蕉", "苹果", "苹果", "苹果" };

	KeyValue::BSTree<string, int> countTree;
	for (auto& str : arr)
	{
		//BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.Find(str);
		if (ret)
		{
			ret->_value++;
		}
		else
		{
			countTree.Insert(str, 1);
		}
	}

	countTree.InOrder();
}
int main()
{
	// TestBSTree1();
	// TestBSTree2();
 
	TestBSTree3();
	TestBSTree4();

	return 0;
}