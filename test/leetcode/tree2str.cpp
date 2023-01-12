void _tree2str(TreeNode* root,string& s)
    {
        if(root == nullptr)
            return;
        s += to_string(root->val);
        if(root->left || root->right)
        {
            s += '(';
            _tree2str(root->left,s);
            s += ')';
        }
        if(root->right)
        {
            s += '(';
            _tree2str(root->right,s);
            s += ')';
        }
        
    }
    string tree2str(TreeNode* root) {
        string str;
        _tree2str(root,str);
        return str;
    }