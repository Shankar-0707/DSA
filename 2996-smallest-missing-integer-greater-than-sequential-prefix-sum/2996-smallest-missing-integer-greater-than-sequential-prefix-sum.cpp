class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans = nums[0];
        int sum = nums[0];
        unordered_set<int> s;

        for(auto i : nums){
            s.insert(i);
        }

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1] + 1){
                sum+= nums[i];
            }
            else{
                ans = max(ans, sum);
                break;
            }
        }

         ans = max(ans, sum);

        while(true){
            if(s.find(ans) == s.end()){
                return ans;
            }
            else{
                ans++;
            }
        }

        return -1;

    }
};