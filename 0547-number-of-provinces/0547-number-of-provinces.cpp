class Solution {
public:
    unordered_map<int,bool> visited;
    unordered_map<int, vector<int>> adjList;
    int ans = 0;

    void dfs(int n){
        visited[n] = true;

        for(auto nbr : adjList[n]){
            if(!visited[nbr]){
                dfs(nbr);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // Simple ye btana h ki kitne disconnected components h 
        int n = isConnected.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                else{
                    if(isConnected[i][j] == 1){
                        adjList[i].push_back(j);
                    }
                }
            }
        }
        // We have created adjList list now track the ans by any search bfs or dfs
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
};