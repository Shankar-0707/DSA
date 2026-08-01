class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // Brute force Approach - 1 Nested Loop - O(n^2)
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] + nums[j] == target) return {i, j};
            }
        }

        return {-1, -1};
    }
};