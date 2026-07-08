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
    int maxSum;

    int solve(TreeNode* root){
        if(!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int niche = left + right + root->val;

        int koi_ek_side = max(left, right) + root->val;

        int koi_nhi = root->val;

        maxSum = max({maxSum, niche, koi_ek_side, koi_nhi});

        return max(koi_ek_side, koi_nhi);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;

        solve(root);

        return maxSum;
    }
};