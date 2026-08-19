class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // I am stroing the reserved seats in an map of int and unordered_set to
        // detect which row has how many seats reserved
        unordered_map<int, unordered_set<int>> mp;

        for (auto v : reservedSeats) {
            // v[0] -> row number
            // v[1] -> seat number
            mp[v[0]].insert(v[1]);
        }

        int ans = (n - mp.size()) * 2; // for those rows who has not any reserves seats as they can give max 2 grps 

        for (auto &it : mp) {
            auto &s = it.second;
            if (s.empty()) {
                ans +=
                    2; // we cn allocate maximum two groups in an unreserved row
            } else {
                // it means we have reserved seats
                // check for two groups
                if (s.find(2) == s.end() && s.find(3) == s.end() &&
                    s.find(4) == s.end() && s.find(5) == s.end() &&
                    s.find(6) == s.end() && s.find(7) == s.end() &&
                    s.find(8) == s.end() && s.find(9) == s.end()) {
                    ans += 2;
                } else {
                    bool first_grp = false;
                    bool second_grp = false;
                    if (s.find(2) == s.end() && s.find(3) == s.end() &&
                        s.find(4) == s.end() && s.find(5) == s.end()) {
                        ans += 1;
                        first_grp = true;
                    }
                    if (s.find(4) == s.end() && s.find(5) == s.end() &&
                        s.find(6) == s.end() && s.find(7) == s.end() &&
                        first_grp == false) {
                        ans += 1;
                        second_grp = true;
                    }
                    if (s.find(6) == s.end() && s.find(7) == s.end() &&
                        s.find(8) == s.end() && s.find(9) == s.end() &&
                        second_grp == false) {
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }
};