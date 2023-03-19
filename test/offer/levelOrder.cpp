vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> vv;
        if(root == nullptr)
            return vv;
        q.push(root);

        while(!q.empty())
        {
            vector<int> tmp;
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* front = q.front();
                tmp.push_back(front->val);
                q.pop();
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            vv.push_back(tmp);
        }
        return vv;
    }