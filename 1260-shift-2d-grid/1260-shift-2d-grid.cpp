class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> elements;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                elements.push_back(grid[i][j]);
            }
        }

        int shift = k % elements.size();
        reverse(elements.begin(), elements.end());
        reverse(elements.begin(), elements.begin()+shift);
        reverse(elements.begin()+shift, elements.end());

        int idx = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                grid[i][j] = elements[idx];
                idx++;
            }
        }


        return grid;

    }
};