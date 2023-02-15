#pragma once


template<class K>
struct HashFunc   // �º��� , Ϊ�˿��Ը���ͬ����ȡģ 
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>   // �º��� , �ػ�
{
	// BKDR��ϣ
	size_t operator()(const string& key)
	{
		size_t val = 0;
		for (auto ch : key)
		{
			val *= 131; //abc��acb���������ȵģ�Ϊ����������,*= 131
			val += ch;
		}
		return val;
	}
};

//struct HashFuncString   // �º��� , ֻ���string
//{
//	size_t operator()(const string& key)
//	{
//		size_t val = 0;
//		for (auto ch : key)
//		{
//			val += ch;
//		}
//		return val;
//	}
//};


// ��ɢ�� -- ���ռ�ñ�Ŀ�λ
namespace CloseHash
{
	enum State
	{
		EMPTY,   // ��
		EXIST,   // ����
		DELETE   // ɾ��
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};


	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}

			// �����������˾�����
			if (_tables.size() == 0 || (10 * _size) / _tables.size() >= 7)  // ����  �������� -> 0.7
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V, Hash> newHT;
				newHT._tables.resize(newSize);  // ����������С

				// �ɱ������ӳ�䵽�±�
				for (auto e : _tables)
				{
					if (e._state == EXIST)
					{
						newHT.Insert(e._kv);
					}
				}
				_tables.swap(newHT._tables);   // �����������Զ�����vector����������
			}

			// ����̽�� -- ����һ��һ������ռ��
			Hash hash;
			size_t hashi = hash(kv.first) % _tables.size();

			while (_tables[hashi]._state == EXIST)
			{
				hashi++;
				hashi %= _tables.size();  // �ߵ���β�Ļ����ٴ�ͷ��ʼ
			}

			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_size;


			//// ����̽�� -- ����һ�οռ��ռ��
			//Hash hash;
			//size_t start = hash(kv.first) % _tables.size();
			//size_t hashi = start;
			//size_t i = 0;
			//while (_tables[hashi]._state == EXIST)
			//{
			//	++i;
			//	hashi = start + i * i;  // hash + i ^ 2 (i >= 0)
			//	hashi %= _tables.size();  // �ߵ���β�Ļ����ٴ�ͷ��ʼ
			//}

			//_tables[hashi]._kv = kv;
			//_tables[hashi]._state = EXIST;
			//++_size;


			return true;
		}

		HashData<K, V>* Find(const K& key)  // ����
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			Hash hash;
			size_t start = hash(key) % _tables.size();
			size_t hashi = start;
			while (_tables[hashi]._state != EMPTY)  // �����ڿ�
			{
				if (_tables[hashi]._state != DELETE
					&& _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				++hashi;
				hashi %= _tables.size();

				if (hashi == start)  // ȫ����DELETEɾ�������
				{
					break;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)  // ɾ�� 
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_size;
				return true;
			}
			else
			{
				return false;
			}
		}

		void Print()
		{
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				if (_tables[i]._state == EXIST)
				{
					printf("[%d:%d] ", i, _tables[i]._kv.first);
				}
				else
				{
					printf("[%d:*] ", i);
				}
			}
			cout << endl;
		}
	private:
		//vector<pair<K, V>> _tables;
		vector<HashData<K, V>> _tables;
		size_t _size = 0;   // �洢���ٸ���Ч����
	};

	void TestHash1()
	{
		int a[] = { 1, 11, 4, 15, 26, 7, 44 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Print();

		ht.Erase(4);
		cout << ht.Find(44)->_kv.first << endl;
		cout << ht.Find(4) << endl;
		ht.Print();

		ht.Insert(make_pair(-2, -2)); // �����ڲ��ұȽϵ�ʱ����������Ϊ�޷���������ȡģ
		ht.Print();
	}

	void TestHash2()
	{
		string arr[] = { "apple", "banana", "watermelon", "watermelon", "banana",  "banana" };

		//HashTable<string, int, HashFuncString> countHT; // ͳ�ƴ���
		HashTable<string, int> countHT;
		for (auto& str : arr)
		{
			auto ptr = countHT.Find(str);
			if (ptr)
			{
				ptr->_kv.second++;
			}
			else
			{
				countHT.Insert(make_pair(str, 1));
			}
		}
		countHT.Print();
	}

	void TestHash3()
	{
		HashFunc<string> hash;
		cout << hash("abcd") << endl;
		cout << hash("bcad") << endl;
		cout << hash("eat") << endl;
		cout << hash("tae") << endl;
		cout << hash("aadd") << endl;
		cout << hash("abcd") << endl << endl;

		cout << hash("abcd") << endl;
		cout << hash("bcad") << endl;
		cout << hash("eat") << endl;
		cout << hash("tae") << endl;
		cout << hash("aadd") << endl;
		cout << hash("abcd") << endl << endl;
	}
}



// ��ɢ�� -- ����������ϣͰ
namespace HashBucket
{
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{}
	};
	
	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		~HashTable()
		{
			// �ͷ�Ͱ�ռ�
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}


		inline size_t __stl_next_prime(size_t n)
		{
			// ������
			static const size_t __stl_num_primes = 28;  // static const ֻ������int���Ը�ȱʡֵ
			static const size_t __stl_prime_list[__stl_num_primes] =
			{
				  53,         97,         193,       389,       769,
				  1543,       3079,       6151,      12289,     24593,
				  49157,      98317,      196613,    393241,    786433,
				  1572869,    3145739,    6291469,   12582917,  25165843,
				  50331653,   100663319,  201326611, 402653189, 805306457,
				  1610612741, 3221225473, 4294967291
			};

			//const size_t* first = __stl_prime_list;
			//const size_t* last = __stl_prime_list + __stl_num_primes;
			//const size_t* pos = lower_bound(first, last, n);  // �������У��ҵ�һ����n���ֵ
			//return pos == last ? *(last - 1) : *pos;

			for (size_t i = 0; i < __stl_num_primes; ++i)
			{
				if (__stl_prime_list[i] > n)
				{
					return __stl_prime_list[i];
				}
			}

			return -1;
		}


		bool Insert(const pair<K, V>& kv)
		{
			// ȥ��
			if (Find(kv.first))
			{
				return false;
			}

			Hash hash;

			// �������ӵ�1������
			if (_size == _tables.size())
			{
				//size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				vector<Node*> newTables;
				//newTables.resize(newSize, nullptr); // ����������С
				newTables.resize(__stl_next_prime(_tables.size()), nullptr);
				// �ɱ��нڵ��ƶ�ӳ���±�
				for (size_t i = 0; i < _tables.size(); ++i)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						size_t hashi = hash(cur->_kv.first) % newTables.size();
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}

			size_t hashi = hash(kv.first) % _tables.size();
			// ͷ��
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_size;

			return true;
		}

		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
			{
				return nullptr;
			}

			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			if (_tables.size() == 0)
			{
				return false;
			}

			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr)	// 1��ͷɾ
					{
						_tables[hashi] = cur->_next;
					}
					else                  // 2���м�ɾ
					{
						prev->_next = cur->_next;
					}

					delete cur;
					--_size;

					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return false;
		}

		size_t Size()
		{
			return _size;
		}

		// ��ĳ���
		size_t TablesSize()
		{
			return _tables.size();
		}

		// Ͱ�ĸ���
		size_t BucketNum()
		{
			size_t num = 0;
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				if (_tables[i])
				{
					++num;
				}
			}
			return num;
		}

		// ����Ͱ�ĳ���
		size_t MaxBucketLenth()
		{
			size_t maxLen = 0;
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				size_t len = 0;
				Node* cur = _tables[i];
				while (cur)
				{
					++len;
					cur = cur->_next;
				}

				/*if (len > 0)
				{
					printf("[%d]��Ͱ����: %d\n", i, len);
				}*/

				if (len > maxLen)
				{
					maxLen = len;
				}
			}
			return maxLen;
		}
	private:
		vector<Node*> _tables;
		size_t _size = 0;  // �洢����Ч���ݸ���
	};

	/*void TestHash1()
	{
		int a[] = { 1, 11, 4, 15, 26, 7, 44, 25, 77, 35 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(22, 22));

		ht.Erase(44);
		ht.Erase(4);
	}

	void TestHash2()
	{
		string arr[] = { "apple", "banana", "watermelon", "watermelon", "banana",  "banana" };

		//HashTable<string, int, HashFuncString> countHT; // ͳ�ƴ���
		HashTable<string, int> countHT;
		for (auto& str : arr)
		{
			auto ptr = countHT.Find(str);
			if (ptr)
			{
				ptr->_kv.second++;
			}
			else
			{
				countHT.Insert(make_pair(str, 1));
			}
		}
	}

	void TestHash3()
	{
		int n = 10000000;
		vector<int> v;
		v.reserve(n);
		srand(time(0));
		for (int i = 0; i < n; ++i)
		{
			//v.push_back(i);
			v.push_back(rand() + i);  // �ظ���
			//v.push_back(rand());  // �ظ���
		}

		size_t begin1 = clock();
		HashTable<int, int> ht;
		for (auto e : v)
		{
			ht.Insert(make_pair(e, e));
		}
		size_t end1 = clock();

		cout << "���ݸ���:" << ht.Size() << endl;
		cout << "��ĳ���:" << ht.TablesSize() << endl;
		cout << "Ͱ�ĸ���:" << ht.BucketNum() << endl;
		cout << "ƽ��ÿ��Ͱ�ĳ���:" << (double)ht.Size() / (double)ht.BucketNum() << endl;
		cout << "���Ͱ�ĳ���:" << ht.MaxBucketLenth() << endl;
		cout << "��������:" << (double)ht.Size() / (double)ht.TablesSize() << endl;

	}*/
}