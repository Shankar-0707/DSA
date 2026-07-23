class Solution {
public:

    int solve(int i, int j, string& text1, string& text2, vector<vector<int>> &dp){
        if(i >= text1.length() || j >= text2.length()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return dp[i][j] =  1 + solve(i+1, j+1, text1, text2, dp);
        }

        int one = solve(i, j+1, text1, text2, dp);
        int two = solve(i+1, j, text1, text2, dp);

        return dp[i][j] = max(one, two);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        int i=0, j=0; // i text1 wali string per traverse krne ke liye or j text2 wali string per 
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(i,j, text1, text2, dp);
    }
};