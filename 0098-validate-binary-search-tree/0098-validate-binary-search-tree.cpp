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

    bool helper(TreeNode* root, long long lb, long long ub){
        if(!root) return true;

        bool one = (root->val < ub && root->val > lb);
        bool two = helper(root->left, lb, root->val);
        bool three = helper(root->right, root->val, ub);

        return (one && two && three);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        long long lb = LLONG_MIN;
        long long ub = LLONG_MAX;
        return helper(root, lb, ub);
    }
};