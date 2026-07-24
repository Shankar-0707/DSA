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
            return dp[i][j] =  solve(word1, word2, i+1, j+1, dp);
        }

        // yha hm teeno case guess krenge 
        int insert = 1 + solve(word1, word2, i, j+1, dp);

        int del = 1 + solve(word1, word2, i+1, j, dp);

        int rep = 1 + solve(word1, word2, i+1, j+1, dp);

        return dp[i][j] = min({insert, del, rep});
    }

    int tab(string& word1, string& word2){
        int n1 = word1.length();
        int n2 = word2.length();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i=n2; i>=0; i--){
            dp[n1][i] = n2-i;
        }

        for(int i=n1; i>=0; i--){
            dp[i][n2] = n1-i;
        }

        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]});
                }
            }
        }

        return dp[0][0];
    }

    int so(string &word1, string &word2){
        int n1 = word1.length();
        int n2 = word2.length();

        vector<int> curr(n2+1);
        vector<int> next(n2+1);

        for(int j=0; j<=n2; j++){
            next[j] = n2-j;
        }

        for(int i=n1-1; i>=0; i--){
            curr[n2] = n1 - i; 
            for(int j=n2-1; j>=0; j--){
                if(word1[i] == word2[j]){
                    curr[j] = next[j+1];
                }
                else{
                    curr[j] = 1 + min({curr[j+1], next[j], next[j+1]});
                }
            }
            next = curr;
        }

        return next[0];
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        // vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return so(word1, word2);
    }
};