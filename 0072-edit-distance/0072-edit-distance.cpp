class Solution {
public:

    int solve(string &word1, string &word2, int i, int j, vector<vector<int>>& dp){
        // Base case
        if(i >= word1.length() && j < word2.length()){
            // iska mtlb h ki word 1 khtm ho ghya h and word2 still bcha h to hme insert krne pdenge character
            return (word2.length() - j);
        }
        if(j >= word2.length() && i < word1.length()){
            return (word1.length() - i);
        }

        if(i == word1.length() && j == word2.length()){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];


        if(word1[i] == word2[j]){
            return solve(word1, word2, i+1, j+1, dp);
        }

        // yha hm teeno case guess krenge 
        int insert = 1 + solve(word1, word2, i, j+1, dp);

        int del = 1 + solve(word1, word2, i+1, j, dp);

        int rep = 1 + solve(word1, word2, i+1, j+1, dp);

        return dp[i][j] = min({insert, del, rep});
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};