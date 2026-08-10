class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, false);
        // dp[i] hme ye btayega ki is tone per winning posiition h ya nhi 

        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                if(dp[i - (j*j)] == false){
                    dp[i] = true; // mtlb hm is move se jeet skte h kyoki n-sq htane per samne wala haar jayega 
                    break;
                }
            }
        }

        return dp[n];
    }
};