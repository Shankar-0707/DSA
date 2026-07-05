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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int,int>>> q;
        // unordered_map<int, vector<TreeNode*>> mp;
        map<int, map<int, multiset<int>>> mp; // first int col second row and third wala values ke liye also hme sorted chaiye sb isiliye map use kra 
        if(!root) return {};

        q.push({root, {0,0}});

        while(!q.empty()){
            auto elem = q.front();
            TreeNode* temp = elem.first;
            int row = elem.second.first;
            int col = elem.second.second;
            q.pop();

            mp[col][row].insert(temp->val);
            if(temp->left){
                q.push({temp->left, {row+1, col-1}});
            }

            if(temp->right){
                q.push({temp->right, {row+1, col+1}});
            }
        }
        for(auto &i : mp){
            vector<int> temp;
            for(auto &j : i.second){
                for(auto k : j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};