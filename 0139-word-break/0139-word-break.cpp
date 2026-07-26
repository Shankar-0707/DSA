class Solution {
public:

    bool solve(int idx, string& s, unordered_set<string>& st, vector<int> &dp){
        if(idx >= s.length()) return true;

        if(st.find(s) != st.end()) return true;

        if(dp[idx] != -1) return dp[idx];

        for(int l=1; l<=s.length(); l++){
            string temp = s.substr(idx, l);

            if(st.find(temp) != st.end() && solve(idx+l, s, st, dp)){
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        unordered_set<string> st;
        for(auto &word : wordDict){
            st.insert(word);
        }

        vector<int> dp(s.length()+1, -1);

        return solve(0, s, st, dp);
    }
};