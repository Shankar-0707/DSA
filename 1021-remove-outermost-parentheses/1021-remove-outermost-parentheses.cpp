class Solution {
public:
    string remove(string &str){
        if(str.length() == 0) return "";

        return str.substr(1,str.length()-2);
    }

    string removeOuterParentheses(string s) {
        string temp = "";
        string ans = "";
        int open = 0;
        int close = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
                temp += s[i];
            } else {
                close++;
                temp += s[i];
            }

            if (open == close) {
                string toAdd = remove(temp);
                ans += toAdd;
                temp = "";
            }
        }

        if (open == close) {
            string toAdd = remove(temp);
            ans += toAdd;
            temp = "";
        }

        return ans;
    }
};