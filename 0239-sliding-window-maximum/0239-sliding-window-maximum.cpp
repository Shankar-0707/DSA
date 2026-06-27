class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;

        for(int i=0; i<k; i++){
            int element = nums[i];

            while(!q.empty() && nums[q.back()] < element){
                q.pop_back();
            }
            q.push_back(i);
        }

        // ans store krenge
        int index = q.front();
        int element = nums[index];
        ans.push_back(element);

        // process the remainig window
        for(int i = k; i<nums.size(); i++){
            int element2 = nums[i];
            // process of removal 
            if(!q.empty() && (q.front() < i-k+1)){
                q.pop_front();
            }

            while(!q.empty() && nums[q.back()] < element2){
                q.pop_back();
            }
            q.push_back(i);

            // ans store
             int index = q.front();
            int element = nums[index];
            ans.push_back(element);


        }

        return ans;
    }
};