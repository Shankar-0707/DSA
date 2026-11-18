class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        int n = s.length();
        
        int i = 0;
        while(i<n){
            if(i+1 < n && s[i] != s[i+1]){
                ans+=1;
            }
            i+=2;
        }
        return ans;
    }
};