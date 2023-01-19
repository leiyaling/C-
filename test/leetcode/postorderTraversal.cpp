vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();
           //右子树为空或者右子树访问过了，才能访问根
            //top->right == prev ---> 右子树访问过 
            if(top->right == nullptr || top->right == prev)
            {
                v.push_back(top->val);
                prev = top;
                st.pop();
            }
            else
            {
                //右子树没有访问过，继续访问
                cur = top->right;
            }
            
        }
        return v;
    }