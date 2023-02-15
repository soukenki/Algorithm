#pragma once

#include <iostream>
#include <string>
using namespace std;


namespace Key
{
	template<class K> // Kay
	struct BSTreeNode  // ����
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		BSTreeNode(const K& key) // ����
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}

	};

	template<class K>
	class BSTree  // BinarySearchTree
	{
		typedef BSTreeNode<K> Node;

	public:
		bool Insert(const K& key) // ����ڵ�
		{
			if (_root == nullptr)
			{
				_root = new Node(key); // ������Ϊ��
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)  // �ҵ���Ϊֹ
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;  // ��������ͬ��key����
				}
			}

			// curΪ�գ�����+���Ӹ��ڵ�
			cur = new Node(key);
			if (parent->_key > key)
			{
				parent->_left = cur;
			}
			else
			{
				parent->_right = cur;
			}
			return true;
		}

		bool Find(const K& key)  // ���ҽڵ�
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else  // _key��key���
				{
					return true;
				}
			}
			return false;
		}


		bool Erase(const K& key) // ɾ���ڵ�
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					// key��_key��ȣ���ʼɾ��
					// 1����Ϊ��
					// 2����Ϊ��
					// 3�����Ҷ���Ϊ��
					if (cur->_left == nullptr)  // 1
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
						cur = nullptr;
					}
					else if (cur->_right == nullptr) // 2
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
						cur = nullptr;
					}
					else  // 3
					{
						// �滻��ɾ��
						// �ҵ�����������С�ڵ�����滻
						Node* minParent = cur;
						Node* min = cur->_right;
						while (min->_left)
						{
							minParent = min;
							min = min->_left;
						}

						swap(cur->_key, min->_key);
						if (minParent->_left == min)
							minParent->_left = min->_right;
						else
							minParent->_right = min->_right;

						delete min;
					}

					return true;
				}
			}

			return false;
		}

		void InOrder() // ���ã�Ϊ���޲� + ����˽�е�_root
		{
			_InOrder(_root);
			cout << endl;
		}
		
		// �����ǵݹ�汾///////////////////////////

		bool FindR(const K& key) // �ݹ����
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key) // �ݹ����
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key) // �ݹ�ɾ��
		{
			return _EraseR(_root, key);
		}

		// BSTree() {}  // ����
		// 
		// C++11�е��÷���ǿ������������Ĭ�ϵĹ���
		BSTree() = default;

		BSTree(const BSTree<K>& t) // ��������
		{
			_root = _Copy(t._root);
		}

		// t2 = t1
		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree() // ����
		{
			_Destory(_root);
		}

	private:
		void _InOrder(Node* root) // �����ӡ
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

		Node* _Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}

			Node* copyRoot = new Node(root->_key);
			copyRoot->_left = _Copy(root->_left);
			copyRoot->_right = _Copy(root->_right);
			return copyRoot;
		}

		void _Destory(Node*& root)
		{
			if (root == nullptr)
			{
				return;
			}

			_Destory(root->_left); // ���ε���_leftָ��ı���
			_Destory(root->_right);
			delete root;
			root = nullptr;
		}



		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}

			if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else
			{
				return true;
			}
		}

		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				root == new Node(key);
				return true;
			}

			if (root->_key > key)
			{
				return _InsertR(root->_left, key); // ���ε���_leftָ��ı���
			}
			else if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else
			{
				return false;  // �����������ͬ��key
			}
		}

		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else
			{
				// �ҵ�Ҫɾ����key
				Node* del = root;
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					// ������������ڵ��滻ɾ��
					Node* min = root->_right;
					while (min->_left)
					{
						min = min->_left;
					}
					swap(root->_key, min->_key);
					return _EraseR(root->_right, key);
				}

				delete del;
				return true;
			}
		}

	private:
		Node* _root = nullptr; // ȱʡΪ��
	};

}



// ÿ���ڵ㱣��������ͬ������
namespace KeyValue
{
	// ģ����Ӵʵ� ����+Ӣ�� 
	// ����ˮ������ ˮ����+����
	// ...

	template<class K, class V> // Kay
	struct BSTreeNode  // ����
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value) // ����
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			,_value(value)
		{}

	};

	template<class K, class V>
	class BSTree  // BinarySearchTree
	{
		typedef BSTreeNode<K, V> Node;

	public:
		bool Insert(const K& key, const V& value) // ����ڵ�
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value); // ������Ϊ��
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)  // �ҵ���Ϊֹ
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return false;  // ��������ͬ��key����
				}
			}

			// curΪ�գ�����+���Ӹ��ڵ�
			cur = new Node(key, value);
			if (parent->_key > key)
			{
				parent->_left = cur;
			}
			else
			{
				parent->_right = cur;
			}
			return true;
		}

		Node* Find(const K& key)  // ���ҽڵ�
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else  // _key��key���
				{
					return cur;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			//... ͬ��

			return true;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
	private:

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_InOrder(root->_right);
		}
	private:
		Node* _root = nullptr;
	};
}