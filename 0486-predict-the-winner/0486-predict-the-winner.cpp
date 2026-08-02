class Solution {
public:

    int solve(vector<int>& nums, int i, int j){
        if(i == j) return nums[i];

        return max((nums[i] - solve(nums, i+1, j)), (nums[j] - solve(nums, i, j-1)));
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int i=0; 
        int j=n-1;

        return solve(nums, i, j) >= 0;
    }
};