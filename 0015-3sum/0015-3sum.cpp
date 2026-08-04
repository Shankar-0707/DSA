class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            else{
                int a = i+1; 
                int b = n-1;

                while(a < b){
                    int sum = nums[i] + nums[a] + nums[b];
                    if(sum == 0){
                        ans.push_back({nums[i], nums[a], nums[b]});
                        a++;
                        b--;

                        while(a<b && nums[a] == nums[a-1]) a++;
                        while(a < b && nums[b] == nums[b+1]) b--;
                    }
                    else if(sum > 0){
                        // reduce krna pdega 
                        b--;
                        while(a < b && nums[b] == nums[b+1]) b--;
                    }
                    else{
                        a++;
                        while(a<b && nums[a] == nums[a-1]) a++;
                    }
                }
            }
        }

        return ans;
    }
};