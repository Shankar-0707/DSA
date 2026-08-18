class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        // To store frequncies we use map 
        int n = nums.size();

        unordered_map<int,int> freq;
        for(auto num : nums){
            freq[num]++;
        }

        // case 1 if K == 1 single leemente subaaray so the element which occurs with freq 1 and is bigger will be the answer 
        if(k == 1){
            int ans = -1;
            for(auto i : freq){
                if(i.second == 1){
                    ans = max(ans, i.first);
                }
            }

            return ans;
        }


        // case 2 if k == n then the element which is bigger of all is the answer 
        if(k == n){
            int ans = *max_element(nums.begin(), nums.end());
            return ans;
        }


        // rest cases 1 < k < n
        // it means only corner elements are our answer either nums[0] or nums[n-1]
        // the element which occurs more than 1 times is not the answer 
        if(freq[nums[0]] == 1 && freq[nums[n-1]] == 1){
            return max(nums[0], nums[n-1]);
        }

        if(freq[nums[0]] == 1 && freq[nums[n-1]] > 1){
            return nums[0];
        }

        if(freq[nums[0]] > 1 && freq[nums[n-1]] == 1){
            return nums[n-1];
        }

        return -1;
    }
};