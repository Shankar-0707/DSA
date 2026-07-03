/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void helper(TreeNode* root, vector<int>& ans){
        if(!root) return;

        // process kro left tk 
        helper(root->left, ans);

        // process kro node ko 
        ans.push_back(root->val);

        // process kro right tk 
        helper(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // Left Node Right
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};