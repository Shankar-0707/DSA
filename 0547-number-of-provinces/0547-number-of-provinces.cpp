class Solution {
public:


    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[node] = 1;

        for(int j=0; j<isConnected.size(); j++){
            if(isConnected[node][j] && !visited[j]){
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> visited(n, 0);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                // agar ith node viisited nhi h to phle uske sare nneigbours per chle jao 
                ans++;
                dfs(i, isConnected, visited);
            }
        }

        return ans;
    }
};