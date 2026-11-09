class Solution {
public:
    typedef pair<int, int> P;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> servers;
        for(int i = 0; i < k; i++) {
            servers.insert(i); 
        }

        priority_queue<P, vector<P>, greater<P>> busyServers;

        vector<int> countRequests(k, 0);

        for(int i = 0; i < arrival.size(); i++) {
            int time = arrival[i];

            while(!busyServers.empty() && busyServers.top().first <= time) {
                int server = busyServers.top().second;

                busyServers.pop();

                servers.insert(server);
            }

            int target = i%k;

            auto it = servers.lower_bound(target);

            if(it == servers.end()) { 
                it = servers.begin();
            }

            if(servers.empty()) {
                continue; 
            }

            int targetServer = *it;

            servers.erase(it); 

            busyServers.push({time + load[i], targetServer});

            countRequests[targetServer]++;

        }

        int maxNumberOfRequests = *max_element(begin(countRequests), end(countRequests)); 

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(countRequests[i] == maxNumberOfRequests) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

