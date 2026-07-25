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

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        return solve(grid, 0, 0, dp);
    }
};