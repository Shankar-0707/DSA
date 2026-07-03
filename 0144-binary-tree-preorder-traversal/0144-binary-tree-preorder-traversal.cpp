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
    vector<int> ans;

    void helper(TreeNode* root){
        if(!root) return;

        // process kro current node ko 
        ans.push_back(root->val);

        // process kro left tk 
        helper(root->left);

        // process kro right tk 
        helper(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
};