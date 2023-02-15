#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"



BTNode* CreatBinaryTree() //手戳一棵二叉树，用于测试
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	// BTNode* node7 = BuyNode(7);

	node1->_left = node2;
	node1->_right = node4;
	node2->_left = node3;
	// node2->_right = node7;   // 判断是否为完全二叉树
	node4->_left = node5;
	node4->_right = node6; 
	return node1;
}

void TestBTNode()
{
	BTNode* root = CreatBinaryTree();
	PrevOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");
	
	PostOrder(root);
	printf("\n");

	printf("TreeSize:%d\n", TreeSize(root));  //6

	printf("LeafSize:%d\n", TreeLeafSize(root));  //3

	printf("KLevel:%d\n", TreeKLevel(root, 2)); //2

	printf("TreeDepth:%d\n", TreeDepth(root)); //3

	LevelOrder(root);

	printf("TreeComplete:%d\n", TreeComplete(root));

	TreeDestory(root);
}

int main()
{
	TestBTNode();
	return 0;
}