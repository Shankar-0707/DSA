class Solution {
public:

    int solve(int index, int prev_index, vector<int>& nums, vector<vector<int>> &dp){
        if(index >= nums.size()) return 0;

        if(dp[index][prev_index+1] != -1) return dp[index][prev_index+1];
        int len = 0;
        
        // include 
        if(prev_index == -1 || nums[index] > nums[prev_index]){
            len = max(1 + solve(index+1, index, nums, dp), len);
        }
        
        len = max(solve(index+1, prev_index, nums, dp), len);
        
        dp[index][prev_index+1] = len;
        return len;

    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev_index = -1;
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(0, prev_index, nums, dp);
    }
};