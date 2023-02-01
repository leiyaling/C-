#pragma once
#include <assert.h>
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;

	int _bf;//balance factor  �������߶�-�������߶�

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

		//����ڵ�
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

		//����ƽ��
		//1������ƽ������ �������ڵ㵽���ڵ������·����
		//2�������쳣ƽ�����ӣ���Ҫ��תƽ�⴦��
		// 
		// 
		//1.cur==parent->left parent->bf--
		//2.cur==parent->right parent->bf++
		//3.�����Ժ�parent->bf==0,���½�������˵������ǰparent->bf�� 1 ���� -1�����ڱ��0��������һ�߱������ˣ�parent���������߶Ȳ��䣩
		//4.�����Ժ�parent->bf==1/-1,�������ϸ��¡���˵������ǰparent->bf��0�����ڱ�� 1 ���� -1����һ����������ˣ�parent���������߶ȸı䣩
		//5.�����Ժ�parent->bf==2/-2,parent���������Ѿ���ƽ�⣬��Ҫ��ת����
		while (parent)
		{
			// ����˫�׵�ƽ������
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;

			// ���º���˫�׵�ƽ������
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// ����ǰ˫�׵�ƽ��������0�������˫�׵�ƽ����ΪΪ1 ���� -1 ��˵����˫��Ϊ���Ķ������ĸ߶�������һ�㣬�����Ҫ�������ϵ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ˫�׵�ƽ������Ϊ����2��Υ����AVL����ƽ���ԣ���Ҫ����parentΪ������������ת����
				
				if (parent->_bf == -2 || cur->_bf == -1)//�ҵ���
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 || cur->_bf == 1)//����
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
				//�������ƽ������֮ǰ������ƽ�����Ӿ���������
				assert(false);
			}
		}
		return true;
	}
private:
	Node* _root;
};