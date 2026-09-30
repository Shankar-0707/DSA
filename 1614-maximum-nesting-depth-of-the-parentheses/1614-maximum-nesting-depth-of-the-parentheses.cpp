class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int len = 0;
        int n = s.length();
        int i = 0;
        
        while(i<n){
            if(s[i] == '('){
                len++;
                ans = max(len, ans);
            }
            if(s[i] == ')'){
                len--;
            }

            i++;
        }

        return ans;
    }
};