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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while(curr){
            if(curr->left == NULL){
                // iska mtlb hmne left ki sari processing krli 
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* leftChild = curr->left;

                // find predecessor
                while(leftChild->right){
                    leftChild = leftChild->right;
                }

                leftChild->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }

        return ans;
    }
};