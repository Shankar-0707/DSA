class Solution {
public:

    int expand(string &s, int L, int R){
        while(L >= 0 && R < s.length() && s[L] == s[R]){
            L--;
            R++;
        }

        return R-L-1;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;
        int start = -1;
        // hm dono cases odd and even ke liye try krenge 
        for(int i=0; i<n; i++){

            int len1 = expand(s, i,i);
            int len2 = expand(s, i, i+1);

            int len = max(len1, len2);
            if(len > maxLen){
                maxLen = len;
                start = i - (maxLen - 1)/2;
            }
        }

        return s.substr(start, maxLen);
    }
};