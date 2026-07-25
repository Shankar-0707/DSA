class Solution {
public:

    int solve(vector<vector<int>>& grid, int r, int c, vector<vector<int>> &dp){
        if(r == grid.size()-1 && c == grid[0].size()-1) return grid[r][c];
        if(r >= grid.size() || c >= grid[0].size()) return INT_MAX;

        if(dp[r][c] != INT_MAX) return dp[r][c];

        int down = solve(grid, r+1, c, dp);

        int right = solve(grid, r, c+1, dp);

        int ans = min(down, right);
        if(ans == INT_MAX) return dp[r][c] =  INT_MAX;

        return dp[r][c] = grid[r][c] + ans;
    }

    int tab(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[m-1][n-1] = grid[m-1][n-1];

        for(int r = m-1; r>=0; r--){
            for(int c = n-1; c>=0; c--){
                int down = dp[r+1][c];
                int right = dp[r][c+1];
                int ans = min(down, right);
                if(ans == INT_MAX){
                    dp[r][c] = grid[r][c];
                }
                else{
                    dp[r][c] = grid[r][c] + ans;
                }
            }
        }

        return dp[0][0];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        return tab(grid);
    }
};