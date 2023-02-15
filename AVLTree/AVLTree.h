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
	int _bf;          // balance factor  ƽ������ 
					// -1 0 1 �ֱ���� ������

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
				// ���
				return false;
			}
		}

		// ������curΪ��,����+����
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

		// ����󣬿���ƽ��
		// 1������ƽ������
		while (parent) // һֱ���£�ֱ�����ڵ�
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf == 0)  // ƽ�⣬����Ҫ�������ϸ���
			{
				break;
			}
			else if (abs(parent->_bf) == 1)  // abs()����ֵ����
			{
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				// ˵��parent���ڵ������Ѿ���ƽ���ˣ���Ҫ��ת����
				if (parent->_bf == 2 && cur->_bf == 1) // ����
				{
					RotateL(parent); // ����
				}
				else if (parent->_bf == -2 && cur->_bf == -1) // ����
				{
					RotateR(parent); // �ҵ���
				}
				else if (parent->_bf == -2 && cur->_bf == 1) // ����
				{
					RotateLR(parent); // ����˫��
				}
				else if (parent->_bf == 2 && cur->_bf == -1) // ����
				{
					RotateRL(parent); // ����˫��
				}
				else
				{
					assert(false);
				}

				break;
			}
			else
			{
				assert(false);  // -2 >_bf �� _bf > 2
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
	bool _IsBalance(Node* root) // �ݹ������ĸ߶Ȳ� �ж����Ƿ�ƽ��
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
			cout << root->_kv.first << "ƽ�������쳣" << endl;
			return false;
		}

		return abs(diff) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);  // abs����ֵ  
	}

	int Height(Node* root)  // ���ĸ߶�
	{
		if (root == nullptr)
			return 0;

		return max(Height(root->_left), Height(root->_right)) + 1;
	}

	void RotateL(Node* parent)  // ����
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
	
		subR->_bf = parent->_bf = 0;  // ����ƽ������
	}

	void RotateR(Node* parent)  // �ҵ���
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

		subL->_bf = parent->_bf = 0; // ����ƽ������
	}

	void RotateLR(Node* parent) // ����˫��
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

	void RotateRL(Node* parent) // ����˫��
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

	void _InOrder(Node* root)   // �������
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