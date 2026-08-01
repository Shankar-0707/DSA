class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, vector<int>> indexes; // ek number ke mulitple indexes ho skte h 

        for(int i=0; i<n; i++){
            indexes[nums[i]].push_back(i);
        }

        // sort krenge and then apply krenge two pointers 
        sort(nums.begin(), nums.end());

        int a = 0;
        int b = n-1;

        while(a < b){
            // a <= b isiliye nhi rkha kyoki a == b pe ek hi element ko twice time include krlete jo ki nhi kr skte 

            int sum = nums[a] + nums[b];
            if(sum == target){
                // return krna h khuch
                if(nums[a] != nums[b]){
                    // yani ki dono hi value alag alag h to simple dono ke indexes return krdo 
                    return {indexes[nums[a]][0], indexes[nums[b]][0]};
                } 
                else{
                    return {indexes[nums[a]][0], indexes[nums[b]][1]};
                }
            }
            else if(sum < target){
                a++;
            }
            else{
                b--;
            }
        }

        return {-1,-1};
    }
};