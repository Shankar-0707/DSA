class Solution {
public:
    typedef pair<int, int> P; 
    typedef tuple<long, int, int> T; 

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<P, vector<P>, greater<P>> freeServers;
        priority_queue<T, vector<T>, greater<T>> busyServers;

        for(int i = 0; i < n; i++) {
            freeServers.push({servers[i], i}); 
        }

        vector<int> ans(m);

        for(int i = 0; i < m; i++) { 
           
            while(!busyServers.empty() && get<0>(busyServers.top()) <= i) {
                auto [finTime, w, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({w, idx});
            }


            if(freeServers.empty()) {
                auto [finTime, w, idx] = busyServers.top();
                busyServers.pop();
                ans[i] = idx;
                busyServers.push({finTime + tasks[i], w, idx});
            } else { 
                auto [w, idx] = freeServers.top();
                freeServers.pop();
                ans[i] = idx;
                busyServers.push({i + tasks[i], w, idx});
            }
        }

        return ans;
    }
};