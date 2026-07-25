class Solution {
public:
    int solve(int amount, vector<int>& coins, int index, int curr, vector<vector<int>> &dp){
        if(curr == amount){
            return 1;
        }
        if(curr > amount || index >= coins.size()) return 0;

        if(dp[index][curr] != -1) return dp[index][curr];

        // include;
        int inc = solve(amount, coins, index, curr+coins[index], dp);

        // exclude
        int exc = solve(amount, coins, index+1, curr, dp);

        return dp[index][curr] = inc + exc;
    }

    int change(int amount, vector<int>& coins) {
        int index = 0;
        int curr = 0;
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,-1));
        return solve(amount, coins, index, curr, dp);
    }
};