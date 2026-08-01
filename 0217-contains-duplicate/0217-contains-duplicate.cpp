class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Method 1 using map 
        int n = nums.size();
        unordered_map<int,int> freq;

        for(auto num : nums){
            freq[num]++;
        }

        for(auto it : freq){
            if(it.second >= 2) return true;
        }

        return false;
    }
};