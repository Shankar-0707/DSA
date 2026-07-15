class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // second approach use min heap of size k 
        priority_queue<int, vector<int>, greater<int>> q;

        for(auto i : nums){
            q.push(i);

            if(q.size() > k){
                q.pop();
            }
        }

        return q.top();
    }
};