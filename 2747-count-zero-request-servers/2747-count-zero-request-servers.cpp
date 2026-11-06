class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();

        auto cmp = [](vector<int>& v1, vector<int>& v2){
            return v1[1] < v2[1];
        };

        sort(logs.begin(), logs.end(), cmp);

        int q = queries.size();
        vector<pair<int,int>> timeIndex(q);    
        for (int i = 0; i < q; i++) {
            timeIndex[i] = {queries[i], i};
        }

        sort(begin(timeIndex), end(timeIndex));
        vector<int> ans(q);

        int i=0;
        int j=0;

        unordered_map<int,int> mp;

        for(auto [time, idx] : timeIndex){
            int start = time-x;
            int end = time;

            while(j<m && logs[j][1] <= end){
                mp[logs[j][0]]++;
                j++;
            }

            while(i<m && logs[i][1] < start){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]] == 0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }

            ans[idx] = n-mp.size();
        }

        return ans;
    }
};