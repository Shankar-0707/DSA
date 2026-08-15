class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // Approach 2 By Taking entire array 
        int curr_xor = 0;
        for(auto num : nums){
            curr_xor ^= num;
        }

        if(curr_xor != 0) return nums.size();

        // but agar 0 hogya to hm ek element ko remove krke check krenge 
        for(int i=0; i<nums.size(); i++){
            curr_xor ^= nums[i];

            if(curr_xor != 0) return nums.size()-1;
        }

        return 0;
    }
};