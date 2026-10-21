class Solution {
public:

    void bfs(vector<vector<int>> &adjList, int node, vector<int>& visited){
        queue<int> q;
        q.push(node);

        visited[node] = 1;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto nbr : adjList[node]){
                if(!visited[nbr]){
                    visited[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
        return;
    }

    void dfs(vector<vector<int>> &adjList, int node, vector<int>& visited){
        visited[node] = 1;

        for(auto nbr : adjList[node]){
            if(!visited[nbr]){
                dfs(adjList, nbr, visited);
            }
        }

        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // I will make an adjancency list first
        int n = isConnected.size();
        vector<vector<int>> adjList(n + 1);

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (i == j)
                    continue; // every node is connected to selff
                else {
                    if (isConnected[i][j]) {
                        adjList[i + 1].push_back(j + 1);
                        adjList[j + 1].push_back(i + 1);
                    }
                }
            }
        }

        int provinces = 0;

        // BFS
        vector<int> visited(n+1, 0);

        for(int i=1; i<=n; i++){
            if(!visited[i]){
                dfs(adjList, i, visited);
                provinces++;
            }
        }

        return provinces;
    }
};