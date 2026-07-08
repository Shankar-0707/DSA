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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &preOrderIndex, int inorderStart, int inorderEnd, int size){
        // base case
        if(preOrderIndex >= size || inorderStart > inorderEnd) return NULL;

        // process the element from preorder array as it is Node Left Right
        int element = preorder[preOrderIndex];
        preOrderIndex++;

        // make a node of it 
        TreeNode* node = new TreeNode(element);

        // getIndex of this element 
        int index = getIndex(element, inorder);

        // call left side
        node->left = solve(preorder, inorder, preOrderIndex, inorderStart, index-1, size);

        // call to the right side
        node->right = solve(preorder, inorder, preOrderIndex, index+1, inorderEnd, size);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0; // to traverse on preOrder Array
        int size = inorder.size(); // total size of array 
        int inorderStart = 0; // starting index of inorder
        int inorderEnd = size-1; // ending index of inorder
        return solve(preorder, inorder, preOrderIndex, inorderStart, inorderEnd, size);
    }
};