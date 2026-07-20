class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        while(k--){
            int last = grid[m-1][n-1];

            for(int row = m-1; row >= 0; row--){
                for(int col = n-1; col >=0; col--){
                    if(row == 0 && col == 0){
                        grid[row][col] = last;
                    }
                    else if(col == 0 && row > 0){
                        grid[row][col] = grid[row-1][n-1];
                    }
                    else{
                        grid[row][col] = grid[row][col-1];
                    }
                }
            }
        }

        return grid;
    }
};