class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[0];
        if(n == 1) return nums[0];

        int ans = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] < 0){
                swap(mini, maxi);
            }
            mini = min(nums[i], nums[i]*mini);
            maxi = max(nums[i], nums[i]*maxi);


            ans = max(ans, maxi);
        }

        return ans;
    }
};