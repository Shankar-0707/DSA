class Solution {
public:

    bool dfs(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i >= m || i < 0 || j >= n || j < 0) return false; 

        if(grid[i][j] == 1){
            return true;
        }

        // ab yha per 0 h yani open
        grid[i][j] = 1;

        bool up = dfs(grid, i-1, j, m, n);
        bool down = dfs(grid, i+1, j, m, n);
        bool right = dfs(grid, i, j+1, m, n);
        bool left = dfs(grid, i, j-1, m, n);

        return up && down && right && left;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0 && dfs(grid, i, j, m ,n)){
                    count++;
                }
            }
        }

        return count;
    }
};