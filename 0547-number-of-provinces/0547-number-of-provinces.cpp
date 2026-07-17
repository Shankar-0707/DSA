class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected,
             vector<bool>& visited) {
        visited[node] = 1;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> visited(n, 0);
        int ans = 0;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                q.push(i);
                visited[i] = 1;
            }
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int j = 0; j < n; j++) {
                    if (isConnected[node][j] == 1 && !visited[j]) {
                        q.push(j);
                        visited[j] = 1;
                    }
                }
            }
        }

        return ans;
    }
};