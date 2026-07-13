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

class INFO{
    public:
    int minVal, maxVal, sum;
    bool isBST;
};


class Solution {
public:


    INFO solve(TreeNode* root, int &sum){
        if(!root){
            INFO temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = 1;
            return temp;
        }

        // LRN
        INFO left = solve(root->left, sum);
        INFO right = solve(root->right, sum);

        INFO curr;
        curr.minVal = min(left.minVal, min(right.minVal, root->val));
        curr.maxVal = max(left.maxVal, max(right.maxVal, root->val));
        curr.sum = left.sum + right.sum + root->val;
        curr.isBST = (root->val > left.maxVal && root->val < right.minVal && left.isBST && right.isBST);

        if(curr.isBST){
            sum = max(sum, curr.sum);
        }
        return curr;
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        INFO temp = solve(root, ans);
        return ans;
    }
};