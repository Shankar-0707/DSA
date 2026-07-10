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

    TreeNode* solve(TreeNode* root, int s, int e, vector<int>& nums){
        if(s > e) return NULL; // edge case

        int mid = s + (e-s)/2;
        if(root == NULL){
            TreeNode* node = new TreeNode(nums[mid]);
            root = node;
        }

        root->left = solve(root->left, s, mid-1, nums);
        root->right = solve(root->right, mid+1, e, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        TreeNode* root = NULL;
        return solve(root, s, e, nums);
    }
};