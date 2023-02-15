#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "Queue.h"

//二叉树结构
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;



BTNode* BuyNode(BTDataType x); // 新建一个节点


// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);



int TreeSize(BTNode* root); // 节点个数
int TreeLeafSize(BTNode* root); // 叶子节点个数
int TreeKLevel(BTNode* root, int k); // 第k层节点个数

BTNode* TreeFind(BTNode* root, BTDataType x); // 查找值为x的节点


void PrevOrder(BTNode* root);  // 前序遍历 
void InOrder(BTNode* root);  // 中序遍历
void PostOrder(BTNode* root); // 后序遍历

void LevelOrder(BTNode* root); // 层序遍历


int TreeDepth(BTNode* root); // 求树的深度

int TreeComplete(BTNode* root); // 判断是否是完全二叉树


void TreeDestory(BTNode* root); // 销毁