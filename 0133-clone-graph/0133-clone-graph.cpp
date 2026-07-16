/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp; // jo ye btayega ki kis node ke liye konsi cloned_node bni hui h 

    queue<Node*> q;

    void dfs(Node* node, Node* cloned_node){
        for(auto n : node->neighbors){
            if(mp.find(n) == mp.end()){
                // iska mtlb h ki iska cloned node nhi bna abhi tkk 
                Node* clone = new Node(n->val);
                mp[n] = clone;
                cloned_node->neighbors.push_back(clone);
                dfs(n, clone);
            }
            else{
                cloned_node->neighbors.push_back(mp[n]);

            }
        }
    }

    void bfs(Node* node){
     

        while(!q.empty()){
            auto n = q.front();
            q.pop();

            Node* cloned_node = mp[n];

            for(auto i : n->neighbors){
                if(mp.find(i) == mp.end()){
                    // iska mtlb clone kro 
                    Node* clone = new Node(i->val);
                    mp[i] = clone;
                    cloned_node->neighbors.push_back(clone);
                    q.push(i);
                }
                else{
                    cloned_node->neighbors.push_back(mp[i]);
                }
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        mp.clear();
        
        Node* cloned_node = new Node(node->val);
        mp[node] = cloned_node;
        q.push(node);

        // dfs(node, cloned_node);
        bfs(node);
        return cloned_node;
    }
};