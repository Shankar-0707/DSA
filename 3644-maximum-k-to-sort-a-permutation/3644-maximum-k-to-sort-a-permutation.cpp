class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        if(temp == nums) return 0;


        int ans = -1; // -1 isiliye kyoki mujhe sare 1 chaiye taki bitwise and shi result de 
        // nd 2's compl. bhi -1 ka 111.. hota h 

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != temp[i]){
                ans &= nums[i];
            }
        }

        return ans;
    }
};