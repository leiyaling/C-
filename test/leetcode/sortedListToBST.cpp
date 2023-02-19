ListNode* middle(ListNode* left,ListNode* right)
    {
        ListNode* slow = left,*fast = left;;
        while(fast != right && fast->next != right)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    TreeNode* buildTree(ListNode* left,ListNode* right)
    {
        if(left == right)
            return nullptr;
        
        ListNode* mid = middle(left,right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(left,mid);
        root->right = buildTree(mid->next,right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        return buildTree(head,nullptr);
    }