class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
       
        Dfs(root,target);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> path;
    void Dfs(TreeNode* root, int target)
    {
        if(root==nullptr)
            return;
        path.push_back(root->val);
        target-=root->val;
        if(target==0 && root->left==nullptr && root->right==nullptr)
            ret.push_back(path);

        Dfs(root->left,target);
        Dfs(root->right,target);
        path.pop_back();
    }
};