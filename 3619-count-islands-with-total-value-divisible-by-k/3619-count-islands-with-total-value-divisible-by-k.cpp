class Solution {
public:


    void dfs(vector<vector<int>>& grid, int row, int col, int rows, int cols, long long &sum){
        if(row >= rows || row < 0 || col < 0 || col >= cols) return;
        if(grid[row][col] == 0) return;

        // ab yha ek valid cell and value not equal to 0 h 
        sum+= grid[row][col];
        grid[row][col] = 0;

        dfs(grid, row-1, col, rows, cols, sum);
        dfs(grid, row+1, col, rows, cols, sum);
        dfs(grid, row, col-1, rows, cols, sum);
        dfs(grid, row, col+1, rows, cols, sum);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0){
                    long long sum = 0;
                    dfs(grid, i, j, m, n, sum);

                    if(sum % k == 0){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};