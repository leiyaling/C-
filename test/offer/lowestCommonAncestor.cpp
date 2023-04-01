TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while(ancestor != nullptr)
        {
            if(p->val < ancestor->val && q->val < ancestor->val)
            {
                ancestor = ancestor->left;
            }
            else if(p->val > ancestor->val && q->val > ancestor->val)
            {
                ancestor = ancestor->right;
            }
            else
            {
                break;
            }
        }
        return ancestor;
        
    }