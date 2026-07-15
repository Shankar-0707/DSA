class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // first approach max heap of all size and reduxcing it to kth eleme 
        priority_queue<int> q;
        for(auto i : nums){
            q.push(i);
        }

        while(!q.empty() && k > 0){
            auto top = q.top();
            q.pop();

            if(k == 1) return top;
            k--;
        }

        return -1;
    }
};