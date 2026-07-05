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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long maxWidth = 0; // kyoki hm index store krenge or hr depth ke liye index 2^depth tk ja skta h 
        if(!root) return maxWidth;
        queue<pair<TreeNode* , int>> q;
        q.push({root, 1}); // root ko index 1 manre h;

        while(!q.empty()){
            unsigned long long size = q.size();
            unsigned long long firstIndex = q.front().second;
            unsigned long long lastIndex = q.back().second;
            unsigned long long currWidth = lastIndex-firstIndex+1;
            maxWidth = max(maxWidth, currWidth);

            for(int i=0; i<size; i++){
                auto front = q.front();
                q.pop();

                TreeNode* node = front.first;
                unsigned long long index = front.second;

                if(node->left){
                    q.push({node->left, index*2});
                }

                if(node->right){
                    q.push({node->right, index*2 + 1});
                }
            }
            
        }

        return maxWidth;
        
    }
};