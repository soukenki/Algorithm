#pragma once

#include <assert.h>
#include <iostream>
#include <map>
#include <string>
#include <time.h>
#include <algorithm>
using namespace std;


template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	pair<K, V> _kv;    // key->first   value->second
	int _bf;          // balance factor  平衡因子 
					// -1 0 1 分别代表 左中右

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}

};

template<class K, class V>
struct AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)  
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				// 相等
				return false;
			}
		}

		// 到这里cur为空,创建+链接
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		// 插入后，控制平衡
		// 1、更新平衡因子
		while (parent) // 一直更新，直到根节点
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf == 0)  // 平衡，不需要继续向上更新
			{
				break;
			}
			else if (abs(parent->_bf) == 1)  // abs()绝对值函数
			{
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				// 说明parent所在的子树已经不平衡了，需要旋转处理
				if (parent->_bf == 2 && cur->_bf == 1) // 右右
				{
					RotateL(parent); // 左单旋
				}
				else if (parent->_bf == -2 && cur->_bf == -1) // 左左
				{
					RotateR(parent); // 右单旋
				}
				else if (parent->_bf == -2 && cur->_bf == 1) // 左右
				{
					RotateLR(parent); // 左右双旋
				}
				else if (parent->_bf == 2 && cur->_bf == -1) // 右左
				{
					RotateRL(parent); // 右左双旋
				}
				else
				{
					assert(false);
				}

				break;
			}
			else
			{
				assert(false);  // -2 >_bf 或 _bf > 2
			}
		}
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}
private:
	bool _IsBalance(Node* root) // 递归求树的高度差 判断树是否平衡
	{
		if (root == nullptr)
		{
			return true;
		}

		int leftHT = Height(root->_left);
		int rightHT = Height(root->_right);
		int diff = rightHT - leftHT;
		
		if (diff != root->_bf)
		{
			cout << root->_kv.first << "平衡因子异常" << endl;
			return false;
		}

		return abs(diff) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);  // abs绝对值  
	}

	int Height(Node* root)  // 树的高度
	{
		if (root == nullptr)
			return 0;

		return max(Height(root->_left), Height(root->_right)) + 1;
	}

	void RotateL(Node* parent)  // 左单旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		Node* ppNode = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subR;
			}
			else
			{
				ppNode->_right = subR;
			}
			subR->_parent = ppNode;
		}
	
		subR->_bf = parent->_bf = 0;  // 更新平衡因子
	}

	void RotateR(Node* parent)  // 右单旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		Node* ppNode = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}

		subL->_bf = parent->_bf = 0; // 更新平衡因子
	}

	void RotateLR(Node* parent) // 左右双旋
	{
		Node* subL = parent->_left; //30
		Node* subLR = subL->_right; //60
		int bf = subLR->_bf;//-1

		RotateL(parent->_left);
		RotateR(parent);

		subLR->_bf = 0;
		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent) // 右左双旋
	{
		Node* subR = parent->_right; 
		Node* subRL = subR->_left; 
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		subRL->_bf = 0;
		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			subR->_bf = 1;
			parent->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void _InOrder(Node* root)   // 中序遍历
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

private:
	Node* _root = nullptr;
};