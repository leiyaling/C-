vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode*cur = root;
        while(cur || !st.empty())
        {
            //循环每走一次迭代，就是在访问一棵树的开始

            //访问左路节点，左路节点入栈
            while(cur)
            {
                st.push(cur);
                v.push_back(cur->val);
                cur = cur->left;
            }

            //取出节点，访问右路节点
            TreeNode* top = st.top();
            st.pop();

            //子问题形式访问右子树
            cur = top->right;
        }
        return v;
    }