class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(auto num : nums){
            maxi = max(maxi, num);
            mini = min(mini, num);
        }

        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> ans;

        for(int i=mini+1; i<maxi; i++){
            if(s.find(i) == s.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};