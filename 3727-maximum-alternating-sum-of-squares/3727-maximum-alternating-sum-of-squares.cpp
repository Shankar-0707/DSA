class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &num : nums){
            num = abs(num);
        }

        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0;
        int j = n-1;

        long long ans = 0;
        bool flag = true; // true means we are taking bigger one means add 

        while(i<=j){
            if(flag){
                ans+= (nums[i] * nums[i]);
                i++;
            }
            else{
                ans-= (nums[j] * nums[j]);
                j--;
            }
            flag = !flag;
        }
        return ans;
    }
};