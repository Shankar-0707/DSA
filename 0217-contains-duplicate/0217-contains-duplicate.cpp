class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Method 1 using map 
        int n = nums.size();
        unordered_set<int> s;

        for(auto num : nums){
            s.insert(num);
        }

        return !(s.size() == n);
    }
};