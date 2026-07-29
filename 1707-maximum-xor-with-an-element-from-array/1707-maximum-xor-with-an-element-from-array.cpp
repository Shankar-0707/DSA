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
            if(!node) return -1;
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

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
    
        vector<vector<int>> newQ;

        for(int i=0; i<queries.size(); i++){
            newQ.push_back({queries[i][1], queries[i][0], i});
        }

        sort(newQ.begin(), newQ.end());
        Trie* trie = new Trie();
        vector<int> tempAns;

        int j = 0;
        for(int i=0; i<newQ.size(); i++){
            int mi = newQ[i][0];
            int xi = newQ[i][1];
            int maxi = -1;

            while(j < nums.size() && nums[j] <= mi){
                trie->insert(nums[j]);
                j++;
            }
            
            maxi = max(maxi, trie->getmax(xi));
            tempAns.push_back(maxi);
        }

        vector<int> ans(queries.size(), -1);
        int k = 0;
        for(auto v : newQ){
            int idx = v[2];
            int val = tempAns[k++];

            ans[idx] = val; 
        }

        return ans;
    }
};