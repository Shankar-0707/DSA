/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* prev = NULL;

        queue<Node* > q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

          
            if(frontNode == NULL){
                // it means i have traverse an array 
                prev = NULL;

                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(prev == NULL){
                    prev = frontNode;
                }
                else {
                    prev->next = frontNode;
                    prev = frontNode;
                }

                if(frontNode->left){
                    q.push(frontNode->left);
                }

                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }

        }
            return root;
    }
};