class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // To store the continuous freq of the elements in Array

        int left = 0; // Left for calculating the previous information about the elements and right for traversing the array 

        int ans = 0;

        for(int right = 0; right < nums.size(); right++){
            
            // Step 1 -> increase the freq of the new element
            freq[nums[right]]++;

            // Step 2 -> Mainatin the freq in given terms 
            while(left <= right && freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
            }

            // Step 3 -> Compute the answer as this subarraay satisfies the condition
            ans = max(ans, right-left+1);
        }

        return ans;
    }
};