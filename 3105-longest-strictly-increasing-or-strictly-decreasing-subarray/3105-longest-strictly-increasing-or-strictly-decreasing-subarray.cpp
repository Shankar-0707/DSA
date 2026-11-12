class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        // striclty increasing 
        for(int i=0; i<n; i++){
            int temp = INT_MIN;
            int len = 0;
            for(int j=i; j<n; j++){
                if(nums[j] > temp){
                    temp = nums[j];
                    len++;
                    ans = max(ans, len);
                }
                else{
                    temp = nums[j];
                    len = 1;
                }
            }
        }

        // striclty decreasing
        for(int i=0; i<n; i++){
            int temp = INT_MAX;
            int len = 0;
            for(int j=i; j<n; j++){
                if(nums[j] < temp){
                    temp = nums[j];
                    len++;
                    ans = max(ans, len);
                }else{
                    temp = nums[j];
                    len = 1;
                }
            }
        }

        return ans;
    }
};