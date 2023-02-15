#define _CRT_SECURE_NO_WARNINGS 1


#include "BinaryTree.h"

BTNode* BuyNode(BTDataType x) // 新建一个节点
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);

	node->_data = x;
	node->_left = node->_right = NULL;
	return node;
}



void PrevOrder(BTNode* root)        // 前序遍历
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

void InOrder(BTNode* root) // 中序遍历
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

void PostOrder(BTNode* root) // 后序遍历
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

// 层序遍历
// 运用队列，将根节点入队列，当队列不为空的时候，
// 将根节点出队列，同时将左右子树根节点入队。
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

int TreeSize(BTNode* root) // 节点数量
{
	// 分治法：分而治之
	return root == NULL ? 0 :
		TreeSize(root->_left) + TreeSize(root->_right) + 1;
}

int TreeLeafSize(BTNode* root) // 叶子节点的数量
{
	if (root == NULL) // 空节点
		return 0;
	if (root->_left == NULL && root->_right == NULL) // 叶子节点
		return 1;

	// 非空非叶子时，返回 左子树叶子节点+右子树叶子节点
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}

int TreeKLevel(BTNode* root, int k) // 第k层 节点的个数(k >= 1)
{
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevel(root->_left, k - 1)
		+ TreeKLevel(root->_right, k - 1);
}

BTNode* TreeFind(BTNode* root, BTDataType x) // 二叉树查找值为x的节点
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

int TreeDepth(BTNode* root) // 求树的深度
{
	if (root == NULL)
		return 0;
	
	int leftDepth = TreeDepth(root->_left);
	int rightDepth = TreeDepth(root->_right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int TreeComplete(BTNode* root) // 判断是否是完全二叉树
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
			// 遇到空以后，则跳出层序遍历
			break;
		}
	}

	// 1、如果后面全是空，则是完全二叉树
	// 2、如果空后面还有非空，则不是完全二叉树
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);  // 是完全二叉树的话，front一直为NULL
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

void TreeDestory(BTNode* root) // 销毁
{
	if (root == NULL)
		return;

	TreeDestory(root->_left);
	TreeDestory(root->_right);
	printf("%p:%d\n", root, root->_data);
	free(root);
}