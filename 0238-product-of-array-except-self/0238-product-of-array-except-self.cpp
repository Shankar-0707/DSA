class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // To complete it in O(1) extra space prefix array should be treated as answer array 

        vector<int> prefix(n, 1);
       
        int suff = 1;

        for(int i=1; i<n; i++){
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        for(int i = n-1; i>=0; i--){
            prefix[i] = prefix[i] * suff;
            suff = suff*nums[i];
        }

        return prefix;
    }
};