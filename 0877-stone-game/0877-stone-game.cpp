class Solution {
public:

    int solve(vector<int>& piles, int i, int j, vector<vector<int>> &dp){
        if( i == j ){
            return piles[i];
        }
        if(dp[i][j] != INT_MIN) return dp[i][j]; 

        return dp[i][j] = max((piles[i] - solve(piles, i+1, j, dp)), (piles[j] - solve(piles, i, j-1, dp)));
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int i = 0;
        int j = n-1;
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MIN));
        return solve(piles, i, j, dp) > 0 ;
    }
};