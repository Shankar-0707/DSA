class Solution {
public:
    int n;

    vector<vector<int>> memo;

    int findMethod(vector<int>& nums, int start, int target){
        int a = lower_bound(nums.begin() + start, nums.end(), target) - nums.begin();

        if(a < n && nums[a] == target){
            return a;
        }

        return -1;
    }

    int solve(int i, int inc, vector<int>& nums){
        if(memo[i][inc] != -1){
            return memo[i][inc];
        }

        int currValue = nums[i] + inc;
        int len = 1;

        int j = findMethod(nums, i+1, currValue+1);
        if(j != -1){
            len = max(len, 1 + solve(j,0, nums));
        }

        j = findMethod(nums, i+1, currValue);
        if(j != -1){
            len = max(len, 1 + solve(j, 1, nums));
        }

        return memo[i][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();

        sort(nums.begin(), nums.end());

        memo.assign(n+1, vector<int>(2, -1));

        int result = 1;
        for(int i=0; i<n; i++){
            result = max({result, solve(i, 0, nums), solve(i, 1, nums)});
        }

        return result;
    }
};