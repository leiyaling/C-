void InOrder(TreeNode* cur,TreeNode*& prev)
	{
		if(cur==nullptr)
		{
			return; 
		}
		InOrder(cur->left,prev);
		cur->left=prev;
		if(prev)
			prev->right=cur;

		prev=cur;
		InOrder(cur->right,prev);
	}
    TreeNode* Convert(TreeNode* pRootOfTree) {
		if(pRootOfTree==nullptr)
			return  nullptr;
        		TreeNode* prev=nullptr;
		InOrder(pRootOfTree, prev);
		TreeNode*head = pRootOfTree;
		while(head->left)
		{
			head = head->left;
		}
		return  head;
    }