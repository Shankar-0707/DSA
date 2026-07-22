class Solution {
public:
    // int solve(int index, int prev_index, vector<int>& nums,
    // vector<vector<int>> &dp){
    //     if(index >= nums.size()) return 0;

    //     if(dp[index][prev_index+1] != -1) return dp[index][prev_index+1];
    //     int len = 0;

    //     // include
    //     if(prev_index == -1 || nums[index] > nums[prev_index]){
    //         len = max(1 + solve(index+1, index, nums, dp), len);
    //     }

    //     len = max(solve(index+1, prev_index, nums, dp), len);

    //     dp[index][prev_index+1] = len;
    //     return len;

    // }

    int solve(int index, int prev_index, vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                int inc = 0;
                if (j == -1 || nums[i] > nums[j]) {
                    inc = 1 + dp[i + 1][i + 1];
                }
                int exc = dp[i + 1][j + 1];
                dp[i][j + 1] = max(inc, exc);
            }
        }

        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev_index = -1;
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));

        // return solve(0, prev_index, nums, dp);
        return solve(0, prev_index, nums);
    }
};