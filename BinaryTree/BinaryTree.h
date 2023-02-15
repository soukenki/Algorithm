#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "Queue.h"

//�������ṹ
typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;



BTNode* BuyNode(BTDataType x); // �½�һ���ڵ�


// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);



int TreeSize(BTNode* root); // �ڵ����
int TreeLeafSize(BTNode* root); // Ҷ�ӽڵ����
int TreeKLevel(BTNode* root, int k); // ��k��ڵ����

BTNode* TreeFind(BTNode* root, BTDataType x); // ����ֵΪx�Ľڵ�


void PrevOrder(BTNode* root);  // ǰ����� 
void InOrder(BTNode* root);  // �������
void PostOrder(BTNode* root); // �������

void LevelOrder(BTNode* root); // �������


int TreeDepth(BTNode* root); // ���������

int TreeComplete(BTNode* root); // �ж��Ƿ�����ȫ������


void TreeDestory(BTNode* root); // ����