class Solution {
public:
    int t[1001][1001];
    int solve(string& text1, string& text2, int i, int j) {
        // base case
        if (i >= text1.length() || j >= text2.length())
            return 0;

        if(t[i][j] != -1) return t[i][j];

        // if char are equal
        if (text1[i] == text2[j]) {
            return t[i][j] =  1 + solve(text1, text2, i + 1, j + 1);
        }
        int one = solve(text1, text2, i + 1, j);
        int two = solve(text1, text2, i, j + 1);

        return t[i][j] = max(one, two);
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(t, -1, sizeof(t));
        return solve(text1, text2, 0, 0);
    }
};