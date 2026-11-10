class Solution {
public:
   

    int solve(int i, int n, vector<int>& costs, vector<int>& dp) {
        if(i == n){
            return 0;
        }
           
        if(dp[i] != -1){
            return dp[i];
        }

        int cost = INT_MAX;

        int j = i + 1; 
        if(j <= n){                               
            cost = solve(j, n, costs, dp) + costs[j - 1] + (j - i) * (j - i);
        }

        j = i + 2;                                    
        if(j <= n){
            cost = min(cost, solve(j, n, costs, dp) + costs[j - 1] + (j - i) * (j - i));
        }

        j = i + 3;                                      
        if(j <= n){
            cost = min(cost, solve(j, n, costs, dp) + costs[j - 1] + (j - i) * (j - i));
        }
        return dp[i] = cost;
    }

    int climbStairs(int n, vector<int>& costs) {
       vector<int> dp(n+1, -1);
        return solve(0, n, costs, dp);
    }
};