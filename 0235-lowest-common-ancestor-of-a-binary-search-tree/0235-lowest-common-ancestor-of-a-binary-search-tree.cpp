/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;
        if((root->val > p->val && root->val < q->val)  || (root->val > q->val && root->val < p->val)) return root;

        if(root->val > p->val && root->val > q->val){
            return solve(root->left, p, q);
        }

        return solve(root->right, p , q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        return solve(root, p, q);
    }
};