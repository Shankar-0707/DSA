class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q; // too store a row aand col
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto node = q.front();
                        q.pop();

                        int row = node.first;
                        int col = node.second;

                        if (row - 1 >= 0 && grid[row - 1][col] == '1' &&
                            !visited[row - 1][col]) {
                            visited[row - 1][col] = true;
                            q.push({row - 1, col});
                        }

                        if (row + 1 < m && grid[row + 1][col] == '1' &&
                            !visited[row + 1][col]) {
                            visited[row + 1][col] = true;
                            q.push({row + 1, col});
                        }

                        if (col-1 >= 0 && grid[row][col-1] == '1' &&
                            !visited[row][col-1]) {
                            visited[row][col-1] = true;
                            q.push({row, col-1});
                        }

                        if (col+1 < n && grid[row][col+1] == '1' &&
                            !visited[row][col+1]) {
                            visited[row][col+1] = true;
                            q.push({row, col+1});
                        }
                    }
                }
            }
        }

        return ans;
    }
};