class Solution {
public:

    void solve(vector<string>& ans, string &curr, int o, int c, int n){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }

        if(o < n){
            curr.push_back('(');
            solve(ans, curr, o+1, c, n);
            curr.pop_back();
        }

        if(c < o){
            curr.push_back(')');
            solve(ans, curr, o, c+1, n);
            curr.pop_back();
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        int open = 0;
        int close = 0;
        solve(ans, curr, open, close, n);
        return ans;
    }
};