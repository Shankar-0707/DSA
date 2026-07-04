class Solution {
public:
    vector<int> ans;

    void helper(TreeNode* root){
        if(!root) return;

        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
};