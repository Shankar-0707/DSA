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

    TreeNode* helper(vector<int>& preorder, int &index, int lb, int ub){
        if(index >= preorder.size()) return NULL;

        TreeNode* root = NULL;

        if(preorder[index] < ub && preorder[index] > lb){
            root = new TreeNode(preorder[index++]);
            root->left = helper(preorder, index, lb, root->val);
            root->right = helper(preorder, index, root->val, ub);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int lb = INT_MIN;
        int ub = INT_MAX;
        int index = 0;
        return helper(preorder, index, lb, ub); 
    }
};