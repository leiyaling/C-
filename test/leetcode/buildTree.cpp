TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,int& previ,int inbegin,int inend) {
        if(inbegin >inend)
            return NULL;
        TreeNode* root = new TreeNode(preorder[previ]);
        int rooti = inbegin;
        while(rooti <= inend)
        {
            if(inorder[rooti] == preorder[previ])
                break;
            else
                ++rooti;
                
        }
        ++previ;
        //[inbegin rooti-1] rooti [rooti+1,inend]
        root->left = _buildTree(preorder,inorder,previ,inbegin,rooti-1);
        root->right = _buildTree(preorder,inorder,previ,rooti+1,inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int previ = 0;
       return  _buildTree(preorder,inorder,previ,0,inorder.size()-1);
    }