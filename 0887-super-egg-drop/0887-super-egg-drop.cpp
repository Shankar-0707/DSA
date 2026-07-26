class Solution {
public:

    int solve(int eggs, int floors, vector<vector<int>> &dp){
        // base case
        if(eggs == 1) return floors; // worst case me hr ek floor try krna pdega 
        if(floors == 0) return 0;
        if(floors == 1) return 1; // yha to hme pta chl hi jayega ki ya to tootega ya nhi 

        if(dp[eggs][floors] != -1) return dp[eggs][floors];

        int ans = INT_MAX;

        int low = 1;
        int high = floors;

        while(low <= high){
            int mid = low + (high-low)/2;

            int break_egg = solve(eggs-1, mid-1, dp);
            int no_break = solve(eggs, floors-mid, dp);

            int worst = max(break_egg, no_break);

            ans = min(ans, 1+ worst);

            if(break_egg > no_break){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        // for(int i=1; i<= floors; i++){
        //     int break_egg = solve(eggs-1, i-1, dp);

        //     int no_break = solve(eggs, floors-i, dp);

        //     int worst = max(break_egg, no_break);

        //     ans = min(ans, 1 + worst);
        // } 

        return dp[eggs][floors] =  ans;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return solve(k, n, dp);
    }
};