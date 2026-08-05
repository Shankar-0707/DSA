class Solution {
public:
    void mark_true(vector<int>& visited, int k,
                   unordered_map<int, vector<int>>& adjList) {
        if (visited[k] == 1)
            return;

        visited[k] = 1;

        for (auto nbr : adjList[k]) {
            mark_true(visited, nbr, adjList);
        }

        return;
    }

    void mark_false(vector<int>& visited, int i,
                    unordered_map<int, vector<int>>& adjList) {
        for (auto nbr : adjList[i]) {
            if (visited[nbr] != 0) {
                visited[nbr] = 0;
                mark_false(visited, nbr, adjList);
            }
        }
        return;
    }

    void make_vector(vector<int>& ans, int n){
        for(int i=0; i<n; i++){
            ans.push_back(i);
        }
        return;
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<int> ans;

        // Step-1 Make Adjacency list;
        unordered_map<int, vector<int>> adjList;

        for (auto& v : invocations) {
            int a = v[0];
            int b = v[1];
            adjList[a].push_back(b);
        }

        // Step-2 make array of n size and make all by false;
        vector<int> visited(n, 0);

        // Step-3 mark bug method and its related invoked method as true
        mark_true(visited, k, adjList);

        // Step-4 Jo jo bhi false wale h ek to vo or unke sath jo jo h unhe bhi
        // false krna h

        // for (int i = 0; i < n; i++) {
        //     if (visited[i] == 0) {
        //         mark_false(visited, i, adjList);
        //     }
        // }

        for(auto &v : invocations){
            int a = v[0];
            int b = v[1];

            if(!visited[a] && visited[b]){
                make_vector(ans, n);
                return ans;
            }
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};