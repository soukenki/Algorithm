#define _CRT_SECURE_NO_WARNINGS 1


#include "BinarySearchTree.h"

void TestBSTree1() // testѭ����
{
	Key::BSTree<int> t;
	int a[] = { 8, 3, 7, 2, 5, 6, 6,0,-1 };
	for (auto e : a)
	{
		t.Insert(e);
	}

	// ���� + ȥ��
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

void TestBSTree2() // test�ݹ��
{
	Key::BSTree<int> t;
	int a[] = { 8, 3, 7, 2, 5, 6, 6,0,-1 };
	for (auto e : a)
	{
		t.Insert(e);
	}


	// ���� + ȥ��
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

void TestBSTree3() // ģ����Ӵʵ�
{
	KeyValue::BSTree<string, string> dict;
	dict.Insert("sort", "����");
	dict.Insert("left", "���");
	dict.Insert("right", "�ұ�");
	dict.Insert("string", "�ַ���");
	dict.Insert("insert", "����");
	string str;
	while (cin >> str)  // д��IO�� Ctrl+z+�س� �˳�
	{
		KeyValue::BSTreeNode<string, string>* ret = dict.Find(str);
		if (ret)
		{
			cout << "��Ӧ������:" << ret->_value << endl;
		}
		else
		{
			cout << "��Ӧ������->�޴˵���" << endl;
		}
	}
}

void TestBSTree4() // ������ֹ���ˮ����
{
	string arr[] = { "�㽶", "ƻ��", "�㽶", "��ݮ", "�㽶", "ƻ��", "ƻ��", "ƻ��" };

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