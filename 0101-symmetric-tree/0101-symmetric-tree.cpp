/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* one, TreeNode* two) {
        if (one == NULL && two == NULL)
            return true;
        if (one == NULL && two != NULL)
            return false;
        if (one != NULL && two == NULL)
            return false;

        if (one->val != two->val)
            return false;

        bool oneA = solve(one->left, two->right);

        bool oneB = solve(one->right, two->left);

        return oneA && oneB;
    }

    bool isSymmetric(TreeNode* root) { return solve(root, root); }
};