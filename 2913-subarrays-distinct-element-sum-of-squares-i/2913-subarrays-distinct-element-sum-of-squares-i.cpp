class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_set<int> s;
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                s.insert(nums[j]);
                ans+= (s.size() * s.size());
            }
            s.clear();
        }

        return ans;
    }
};