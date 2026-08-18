class Solution {
public:
    int t[2501][2501];
    int solve(vector<int>& nums, int i, int prev){
        if( i >= nums.size()){
            return 0;
        }

        if(t[i][prev+1] != -1) return t[i][prev+1];

        int inc = 0;
        // include
        if(prev == -1 || nums[i] > nums[prev]){
            inc = 1 + solve(nums, i+1, i);
        }

        // exclude
        int exc = solve(nums, i+1, prev);

        return t[i][prev+1] = max(inc, exc);
    }

    int lengthOfLIS(vector<int>& nums) {
        // we have to maintain two states one is for curr index and other is for prev index 

        int n = nums.size(); 
        int prev = -1;
        memset(t, -1, sizeof(t));
        return solve(nums, 0, prev);
    }
};