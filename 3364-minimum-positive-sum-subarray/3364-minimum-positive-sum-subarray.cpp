class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        int ans = INT_MAX;

        for(int i=0; i<n; i++){
            int temp = 0;
            for(int j=i; j<n; j++){
                temp+= nums[j];
                int size = j-i+1;
                if(size >= l && size <= r && temp > 0){
                    ans = min(ans, temp);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};