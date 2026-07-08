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

    int getIndex(int element, vector<int>& inorder){
        for(int i=0; i<inorder.size(); i++){
            if(element == inorder[i]){
                return i;
            }
        }

        return -1;
    }

    unordered_map<int,int> mp;

    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int &postOrderIndex, int inorderStart, int inorderEnd, int size){
        // base case
        if(postOrderIndex < 0 || inorderStart > inorderEnd) return NULL;

        // process the element from preorder array as it is Node Left Right
        int element = postorder[postOrderIndex];
        postOrderIndex--;

        // make a node of it 
        TreeNode* node = new TreeNode(element);

        // getIndex of this element 
        // int index = getIndex(element, inorder);
        int index = mp[element];
        // call to the right side
        node->right = solve(postorder, inorder, postOrderIndex, index+1, inorderEnd, size);

        // call left side
        node->left = solve(postorder, inorder, postOrderIndex, inorderStart, index-1, size);


        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size(); // total size of array 
        int inorderStart = 0; // starting index of inorder
        int inorderEnd = size-1; // ending index of inorder
        int postOrderIndex = size-1; // to traverse on preOrder Array
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return solve(postorder, inorder, postOrderIndex, inorderStart, inorderEnd, size);
    }
};