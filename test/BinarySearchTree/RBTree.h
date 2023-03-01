#pragma once
enum Color
{
	RED,
	BLACK
};
template<class T>
struct RBTreeNode
{
	

	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;

	Color _col;

	AVLTreeNode(const T* data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{},
	
};

template<class T>
class AVLTree
{
	typedef RBTreeNode<T> Node;
public:
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

	}
	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (data > cur->_data)
			{
				parent = cur;
				cur = cur->_right
			}
			else if (data < >> cur->_data)
			{
				parent = cur;
				cur = cur->_left
			}
			else 
			{
				return false;
			}
		}
		//插入节点
		cur = new Node(data);
		cur->_col(RED);
		if (parent->data < data)
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
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = parent->_right;
				//1.uncle存在且为红
				if (uncle && uncle->_col == RED)
				{
					//变色+继续向上处理
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else//2.uncle不存在/uncle存在且为黑
				{
					//        g
					//     p
					//  c

					//        g
					//     p
					//        c
					if (cur == parent->_left)
					{
						//右旋
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;

					}
					if (cur == parent->_right)
					{
						//先左旋再右旋
						RotateL(parent);
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;

					}
					break;
				}
			}
			else // parent == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					// 变色+继续向上处理
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else // 2 + 3、uncle不存在/ 存在且为黑
				{
					//  g    
					//     p
					//        c

					//  g
					//     p
					//  c
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}
private:
	RBTreeNode* _root;
};