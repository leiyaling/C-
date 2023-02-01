#pragma once
#include <assert.h>
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;

	int _bf;//balance factor  右子树高度-左子树高度

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template <class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;
		
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				parentParent->_right = subL;

			subL->_parent = parentParent;
		}

		subL->_bf = parent->_bf = 0;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		Node* parentParent = parent->_parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subR;
			else
				parentParent->_right = subR;

			subR->_parent = parentParent;
		}

		subR->_bf = parent->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		RotateL(parent->_left);
		RotateR(parent);
	}
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;
		RotateR(parent->right);
		RotateL(parent);

		if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	void InOrder()
	{
		_InOrder();
	}
	void _InOrder()
	{

	}
	bool Insert(const pair<K,V>& kv)
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
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		//插入节点
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//控制平衡
		//1、更新平衡因子 （新增节点到根节点的祖先路径）
		//2、出现异常平衡因子，需要旋转平衡处理
		// 
		// 
		//1.cur==parent->left parent->bf--
		//2.cur==parent->right parent->bf++
		//3.更新以后，parent->bf==0,更新结束。（说明更新前parent->bf是 1 或者 -1，现在变成0，矮的那一边被填上了，parent所在子树高度不变）
		//4.更新以后，parent->bf==1/-1,继续向上更新。（说明更新前parent->bf是0，现在变成 1 或者 -1，有一边子树变高了，parent所在子树高度改变）
		//5.更新以后，parent->bf==2/-2,parent所在子树已经不平衡，需要旋转处理。
		while (parent)
		{
			// 更新双亲的平衡因子
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;

			// 更新后检测双亲的平衡因子
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 插入前双亲的平衡因子是0，插入后双亲的平衡因为为1 或者 -1 ，说明以双亲为根的二叉树的高度增加了一层，因此需要继续向上调整
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 双亲的平衡因子为正负2，违反了AVL树的平衡性，需要对以parent为根的树进行旋转处理
				
				if (parent->_bf == -2 || cur->_bf == -1)//右单旋
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 || cur->_bf == 1)//左单旋
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 || cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 || cur->_bf == -1)
				{
					RotateRL(parent);
				}
				break;
			}
			else
			{
				//插入更新平衡因子之前，树中平衡因子就有问题了
				assert(false);
			}
		}
		return true;
	}
private:
	Node* _root;
};