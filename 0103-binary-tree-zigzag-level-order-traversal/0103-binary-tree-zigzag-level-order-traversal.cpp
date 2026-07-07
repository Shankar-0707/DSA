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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bool zig_zag = true;

        if(!root) return ans;
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);

            for(int i=0; i<size; i++){
            int index = zig_zag ? i : size-i-1;
                auto node = q.front();
                q.pop();

                temp[index] = node->val;

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }

            zig_zag = !zig_zag;
            ans.push_back(temp);
        }

        return ans;
    }
};