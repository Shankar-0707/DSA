class Solution {
public:
    bool isPalindrome(string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            else{
                start++;
                end--;
            }
        }

        return true;
    }

    void solve(string &s, int idx, vector<string>& temp, vector<vector<string>>& ans){
        if(idx == s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<s.length(); i++){
            if(isPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                solve(s, i+1, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, temp, ans);
        return ans;
    }
};