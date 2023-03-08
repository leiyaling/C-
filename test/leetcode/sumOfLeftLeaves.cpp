int sumOfLeftLeaves(TreeNode* root) {

        if(root == nullptr)
            return 0;
        
        int sum = 0;
        TreeNode* leftNode = root->left;
        if(leftNode && nullptr == leftNode->left && nullptr == leftNode->right)
            sum += root->left->val;

        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }