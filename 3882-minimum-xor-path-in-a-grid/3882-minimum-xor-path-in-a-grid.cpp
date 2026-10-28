class Solution {
public:

    int m;
    int n;
    vector<vector<vector<bool>>> dp;

    void solve(vector<vector<int>>& grid, int row, int col, int x, int &ans){
        if(row < 0 || row >= m || col < 0 || col >= n) return;
        
        x^= grid[row][col];

        if (dp[row][col][x]) return;

        dp[row][col][x] = true;

        if (row == m - 1 && col == n - 1) {
            ans = min(ans, x);
            return;
        }

        solve(grid, row+1, col, x, ans);
        solve(grid, row, col+1, x, ans);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int x = 0;
        int ans = INT_MAX;
         dp.assign(m, vector<vector<bool>>(
            n, vector<bool>(1024, false)
        ));

        solve(grid, 0,0, x, ans);
        return ans;
    }
};