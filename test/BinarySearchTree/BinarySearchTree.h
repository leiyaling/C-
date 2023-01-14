#pragma once
#include<iostream>
using namespace std;
template<class K>
struct BSTreeNode {
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	
	bool find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
			
	}
	bool Erase(const K& key)
	{
		//找要删除的节点
		Node* parent = nullptr;
		Node* cur = _root;
	
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//找到了，开始删除

				//左子树为空
				if (cur->_left == nullptr)
				{
					//删除的节点是根，需要特殊处理
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else if (parent->_right == cur)
						{
							parent->_right = cur->_right;
						}
					}
					
					delete cur;
				}
				//右子树为空
				else if (cur->_right == nullptr)
				{
					//删除的节点是根，需要特殊处理
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else if (parent->_right == cur)
						{
							parent->_right = cur->_left;
						}
					}
					
					delete cur;
				}
				else
				{
					//左右子树都不为空
					Node* minParent = cur;
					Node* min = cur->_right;
					while (min->_left)
					{
						minParent = min;
						min = min->_left;
					}
					cur->_key = min->_key;

					if (minParent->_left == min)
					{
						minParent->_left = min->_right;
					}
					else
					{
						minParent->_right = min->_right;
					}
					delete min;
				}
				return true;
			}
		}
		return false;
	}
	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}

	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}

	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}
private:
	bool _InsertR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (key < root->_key)
		{
			_InsertR(root->_left, key);
		}
		else if (key > root->_key)
		{
			_InsertR(root->_right, key);
		}
		else
		{
			return false;
		}

	}
	Node* _FindR(Node* root, const K& key)
	{
		if (root == nullptr)
			return nullptr;
		if (key < root->_key)
		{
			_FindR(root->_left, key);
		}
		else if (key > root->_key)
		{
			_FindR(root->_right, key);
		}
		else
		{
			return root;
		}
	}
	bool _EraseR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (key < root->_key)
		{
			_EraseR(root->_left, key);
		}
		else if (key > root->_key)
		{
			_EraseR(root->_right, key);
		}
		else
		{
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
				Node* min = root->_right;
				while (min->_left)
					min = min->_left;

				swap(root->_key, min->_key);
				// 递归到右子树去删除
				return _EraseR(root->_right, key);
			}
			delete del;
			return true;
		}

	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root;
};
namespace KV
{
	template<class K,class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;


		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};
	template<class K,class V>
	class BSTree
	{
		typedef BSTreeNode<K,V> Node;
	public:
		BSTree()
			:_root(nullptr)
		{}
		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key,value);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;
		}

		Node* find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;

		}
		bool Erase(const K& key)
		{
			//找要删除的节点
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					//找到了，开始删除

					//左子树为空
					if (cur->_left == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else if (parent->_right == cur)
							{
								parent->_right = cur->_right;
							}
						}

						delete cur;
					}
					//右子树为空
					else if (cur->_right == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_left;
							}
							else if (parent->_right == cur)
							{
								parent->_right = cur->_left;
							}
						}

						delete cur;
					}
					else
					{
						//左右子树都不为空
						Node* minParent = cur;
						Node* min = cur->_right;
						while (min->_left)
						{
							minParent = min;
							min = min->_left;
						}
						cur->_key = min->_key;
						cur->_value = min->_value;

						if (minParent->_left == min)
						{
							minParent->_left = min->_right;
						}
						else
						{
							minParent->_right = min->_right;
						}
						delete min;
					}
					return true;
				}
			}
			return false;
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
		Node* _root;
	};
	void TestBSTree()
	{
		// 统计语言出现次数
		string arr[] = { "C++", "C语言","Python", "Java", "C语言", "C++", "C++", "C语言", "C++", "Java", "C++", "Java" };
		BSTree<string, int> countTree;
		for (auto& str : arr)
		{
			//BSTreeNode<string, int>* ret = countTree.find(str);
			auto ret = countTree.find(str);
			if (ret != nullptr)
			{
				ret->_value++;
			}
			else
			{
				countTree.Insert(str, 1);
			}
		}

		countTree.InOrder();
	}
}
void TestBSTree()
{
	BSTree<int> t;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : a)
	{
		t.Insert(e);
	}

	t.InOrder();

	t.EraseR(7);
	t.InOrder();

	t.EraseR(5);
	t.InOrder();

	t.EraseR(0);
	t.InOrder();

	t.EraseR(1);
	t.InOrder();

	for (auto e : a)
	{
		t.EraseR(e);
		t.InOrder();
	}
	t.InOrder();
}

