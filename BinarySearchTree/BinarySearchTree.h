#pragma once

#include <iostream>
#include <string>
using namespace std;


namespace Key
{
	template<class K> // Kay
	struct BSTreeNode  // 公开
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;

		BSTreeNode(const K& key) // 构造
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
		bool Insert(const K& key) // 插入节点
		{
			if (_root == nullptr)
			{
				_root = new Node(key); // 整棵树为空
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)  // 找到空为止
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
					return false;  // 不允许相同的key插入
				}
			}

			// cur为空，插入+链接父节点
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

		bool Find(const K& key)  // 查找节点
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
				else  // _key与key相等
				{
					return true;
				}
			}
			return false;
		}


		bool Erase(const K& key) // 删除节点
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
					// key与_key相等，开始删除
					// 1、左为空
					// 2、右为空
					// 3、左右都不为空
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
						// 替换法删除
						// 找到右子树中最小节点进行替换
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

		void InOrder() // 套用，为了无参 + 调用私有的_root
		{
			_InOrder(_root);
			cout << endl;
		}
		
		// 下面是递归版本///////////////////////////

		bool FindR(const K& key) // 递归查找
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key) // 递归插入
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key) // 递归删除
		{
			return _EraseR(_root, key);
		}

		// BSTree() {}  // 构造
		// 
		// C++11中的用法：强调编译器生成默认的构造
		BSTree() = default;

		BSTree(const BSTree<K>& t) // 拷贝构造
		{
			_root = _Copy(t._root);
		}

		// t2 = t1
		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}

		~BSTree() // 析构
		{
			_Destory(_root);
		}

	private:
		void _InOrder(Node* root) // 中序打印
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

			_Destory(root->_left); // 传参的是_left指针的别名
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
				return _InsertR(root->_left, key); // 传参的是_left指针的别名
			}
			else if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else
			{
				return false;  // 不允许插入相同的key
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
				// 找到要删除的key
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
					// 找右树的最左节点替换删除
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
		Node* _root = nullptr; // 缺省为空
	};

}



// 每个节点保存两个不同的数据
namespace KeyValue
{
	// 模拟电子词典 中文+英文 
	// 计算水果数量 水果名+数量
	// ...

	template<class K, class V> // Kay
	struct BSTreeNode  // 公开
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value) // 构造
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
		bool Insert(const K& key, const V& value) // 插入节点
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value); // 整棵树为空
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)  // 找到空为止
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
					return false;  // 不允许相同的key插入
				}
			}

			// cur为空，插入+链接父节点
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

		Node* Find(const K& key)  // 查找节点
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
				else  // _key与key相等
				{
					return cur;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			//... 同上

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