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

    int getHeight(TreeNode* root){
        if(!root) return 0;

        int left = 1 + getHeight(root->left);
        int right = 1 + getHeight(root->right);

        return max(left, right);
    }

    void solve(TreeNode* root, vector<int> &ans, unordered_map<int,int> &check, int height, int level){
        if(!root) return;
        if(check[level] == 0){
            ans.push_back(root->val);
            check[level]++;
        }

        solve(root->right, ans,check, height, level+1);
        solve(root->left, ans,check, height, level+1);
        
    }

    vector<int> rightSideView(TreeNode* root) {
        int height = getHeight(root);
        vector<int> ans;
        unordered_map<int,int> check;

        solve(root, ans, check, height, 0);
        return ans;
    }
};