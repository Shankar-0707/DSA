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

    void inorder_traversal(TreeNode* root, vector<int> &inorder){
        if(!root) return;

        inorder_traversal(root->left, inorder);

        inorder.push_back(root->val);

        inorder_traversal(root->right, inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorder_traversal(root, inorder);

        // yha per inorder ki array bn gyi 
        int n = inorder.size();
        int s = 0;
        int e = n-1;

        while(s<e){
            int sum = inorder[s] + inorder[e];

            if(sum == k) return true;
            else if(sum > k){
                e--;
            }
            else{
                s++;
            }
        }

        return false;
    }
};