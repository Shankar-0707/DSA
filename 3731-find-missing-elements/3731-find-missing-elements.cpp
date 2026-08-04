class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int smallest = nums[0];
        int largest = nums[n-1];
        vector<int> ans;

        for(int i = smallest + 1; i<largest; i++){
            int target = i;
            bool found = false;
            for(int j= 1; j<n-1; j++){
                if(nums[j] == i){
                   found = true;
                }
            }
            if(!found){
                ans.push_back(i);
            }
        }

        return ans;
    }
};