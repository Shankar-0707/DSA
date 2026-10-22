class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int ascending_count = 0;
        int descending_count = 0;

        for(int i=1; i<n; i++){
            ascending_count+= (nums[i] == (nums[i-1] + 1) % n); 
            descending_count+= (nums[i-1] == (nums[i] + 1) % n);
        }

        if(ascending_count == n-1 && nums[0] == 0){
            // iska mtlb already sorted h 
            return 0;
        }

        if(ascending_count == n-1){
            int left = n - nums[0];
            int right = 1 + (nums.back() + 1) + 1;
            return min(left, right);
        }

        if(descending_count == n-1){
            // ek reverse 
            int left = n - nums.back() + 1;

            // left roatation + ek or reverse
            int right = (nums[0]+1) % n + 1;

            return min(left, right);
        }

        return -1;
    }
};