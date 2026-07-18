class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        int fresh_count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
                if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }

        while (!q.empty() && fresh_count) {
            int size = q.size();

            while (size--) {
                auto node = q.front();
                q.pop();
                int row = node.first;
                int col = node.second;

                if (row - 1 >= 0 && grid[row - 1][col] == 1 &&
                    !visited[row - 1][col]) {
                    visited[row - 1][col] = true;
                    q.push({row - 1, col});
                    grid[row-1][col] = 2;
                    fresh_count--;
                }

                if (row + 1 < m && grid[row + 1][col] == 1 &&
                    !visited[row + 1][col]) {
                    visited[row + 1][col] = true;
                    q.push({row + 1, col});
                    grid[row+1][col] = 2;
                    fresh_count--;
                }

                if (col - 1 >= 0 && grid[row][col - 1] == 1 &&
                    !visited[row][col - 1]) {
                    visited[row][col - 1] = true;
                    q.push({row, col - 1});
                    grid[row][col-1] = 2;
                     fresh_count--;
                }

                if (col + 1 < n && grid[row][col + 1] == 1 &&
                    !visited[row][col + 1]) {
                    visited[row][col + 1] = true;
                    q.push({row, col + 1});
                    grid[row][col+1] = 2;
                     fresh_count--;
                }
            }

            ans++;
        }

        return fresh_count == 0 ? ans : -1;
    }
};