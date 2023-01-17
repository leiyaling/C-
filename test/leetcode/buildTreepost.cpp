TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder,int& posti,int inbegin,int inend) {
        if(inbegin > inend)
            return NULL;
        TreeNode* root = new TreeNode(postorder[posti]);
        int rooti = inbegin;
        while(rooti <= inend)
        {
            if(postorder[posti] == inorder[rooti])
                break;
            else
                ++rooti;
        }
        --posti;
        root->right = _buildTree(inorder,postorder,posti,rooti+1,inend);
        root->left = _buildTree(inorder,postorder,posti,inbegin,rooti-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int posti = postorder.size()-1;
        return _buildTree(inorder,postorder,posti,0,inorder.size()-1);
    }