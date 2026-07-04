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
            // jb tk curr node h chlte rho 
            if(!curr->left){
                // agar curr ka left nhih mtlb vhi left node h use process kro yani answer me adaldo 
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                // mtlb ki uski left node h to iska mtlb h curr kisi na kisi ka predecessor hoga 
                TreeNode* leftChild = curr->left;

                while(leftChild->right){
                    leftChild = leftChild->right;
                }

                // ab hme vo noe mil gyi h jiska predecessor curr hoga 
                leftChild->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }

        return ans;
    }
};