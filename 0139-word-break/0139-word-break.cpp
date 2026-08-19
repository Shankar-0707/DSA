class Solution {
public:
    unordered_set<string> st;
    int t[301];
    bool solve(int index, string &s){
        if( index == s.length()) return true;

        if(t[index] != -1) return t[index];

        for(int i=index; i<s.length(); i++){
            string sub = s.substr(index, i-index+1);

            if(st.find(sub) != st.end()){
                if(solve(i+1, s)){
                    return t[index] = true;
                }
            }
        }

        return t[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word : wordDict){
            st.insert(word);
        }
        memset(t, -1, sizeof(t));
        return solve(0, s);
    }
};