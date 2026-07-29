struct Node{
    Node* links[2];

    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    void put(int bit , Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }

public:
    void insert(int num){
        Node* node = root;

        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getmax(int num){
        int maxi = 0;
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = ((num >> i) & 1);
            if(node->containsKey(1-bit)){
                maxi = maxi | (1 << i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxi;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        for(auto &it : nums){
            trie->insert(it);
        }

        int maxi = 0;
        for(auto &it : nums){
            maxi = max(maxi , trie->getmax(it));
        }

        return maxi;
    }
};