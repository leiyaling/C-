//转化为链表相交问题
    bool FindPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
    {
        if(root==nullptr)
            return false;

        path.push(root);//节点不为空，入栈，继续向下寻找

        if(root==x)
            return true;

        if(FindPath(root->left,x,path))
            return true;
        if(FindPath(root->right,x,path))
            return true;
        
        path.pop();//走到这，说明节点为叶子节点，没有找到要找的节点，删掉这个叶子节点，向上一个节点的另一边去找
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pPath,qPath;//两个栈用来存储节点的路径
        FindPath(root,p,pPath);
        FindPath(root,q,qPath);

        //长的先走
        while(pPath.size() != qPath.size())
        {
            if(pPath.size() > qPath.size())
                pPath.pop();
            else
                qPath.pop();
        }

        while(pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();
    }