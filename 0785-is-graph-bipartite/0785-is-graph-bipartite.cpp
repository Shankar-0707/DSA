class Solution {
public:

    bool check(int node, vector<int>& color, vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while(!q.empty()){
            auto n = q.front();
            q.pop();

            for(auto nbr : graph[n]){
                if(color[nbr] == -1){
                    color[nbr] = !color[n];
                    q.push(nbr);
                }
                else if(color[nbr] == color[n]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int i=0; i<V; i++){
            if(color[i] == -1){
                if(check(i, color, graph) == false) return false;
            }
        }

        return true;
    }
};