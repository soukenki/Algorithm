#define _CRT_SECURE_NO_WARNINGS 1


#include "BinaryTree.h"

BTNode* BuyNode(BTDataType x) // �½�һ���ڵ�
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);

	node->_data = x;
	node->_left = node->_right = NULL;
	return node;
}



void PrevOrder(BTNode* root)        // ǰ�����
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	printf("%d ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}

void InOrder(BTNode* root) // �������
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}

	InOrder(root->_left);
	printf("%d ", root->_data);
	InOrder(root->_right);
}

void PostOrder(BTNode* root) // �������
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}


	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%d ", root->_data);
}

// �������
// ���ö��У������ڵ�����У������в�Ϊ�յ�ʱ��
// �����ڵ�����У�ͬʱ�������������ڵ���ӡ�
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d ", front->_data);
		QueuePop(&q);

		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}
	printf("\n");
	QueueDestroy(&q);
}

int TreeSize(BTNode* root) // �ڵ�����
{
	// ���η����ֶ���֮
	return root == NULL ? 0 :
		TreeSize(root->_left) + TreeSize(root->_right) + 1;
}

int TreeLeafSize(BTNode* root) // Ҷ�ӽڵ������
{
	if (root == NULL) // �սڵ�
		return 0;
	if (root->_left == NULL && root->_right == NULL) // Ҷ�ӽڵ�
		return 1;

	// �ǿշ�Ҷ��ʱ������ ������Ҷ�ӽڵ�+������Ҷ�ӽڵ�
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}

int TreeKLevel(BTNode* root, int k) // ��k�� �ڵ�ĸ���(k >= 1)
{
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevel(root->_left, k - 1)
		+ TreeKLevel(root->_right, k - 1);
}

BTNode* TreeFind(BTNode* root, BTDataType x) // ����������ֵΪx�Ľڵ�
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;

	BTNode* ret1 = TreeFind(root->_left, x);
	if (ret1)
		return ret1;

	BTNode* ret2 = TreeFind(root->_right, x);
	if (ret2)
		return ret2;

	return NULL;
}

int TreeDepth(BTNode* root) // ���������
{
	if (root == NULL)
		return 0;
	
	int leftDepth = TreeDepth(root->_left);
	int rightDepth = TreeDepth(root->_right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int TreeComplete(BTNode* root) // �ж��Ƿ�����ȫ������
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{
			// �������Ժ��������������
			break;
		}
	}

	// 1���������ȫ�ǿգ�������ȫ������
	// 2������պ��滹�зǿգ�������ȫ������
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);  // ����ȫ�������Ļ���frontһֱΪNULL
		QueuePop(&q);

		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}

void TreeDestory(BTNode* root) // ����
{
	if (root == NULL)
		return;

	TreeDestory(root->_left);
	TreeDestory(root->_right);
	printf("%p:%d\n", root, root->_data);
	free(root);
}