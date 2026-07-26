class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ans = INT_MIN;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        ans = max((nums[0]*nums[1]*nums[n-1]), (nums[n-1]*nums[n-2]*nums[n-3]));
        return ans;
    }
};