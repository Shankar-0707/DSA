class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, vector<int>> indexes; // ek number ke mulitple indexes ho skte h 

        for(int i=0; i<n; i++){
            indexes[nums[i]].push_back(i);
        }

        // rather then sorting hm ek linear loop chalyenge or hr ek elemnet milne per check krenge ky atarget - that element present h hmare map me or aagar h to uska index agar is element ke index ke equal nhi hua to vhi return krende

        for(int i=0; i<n; i++){
            int elem = nums[i];
            if(indexes.find(target-elem) != indexes.end()){
                // iska mtlb h ki vo element present h 
                for(auto idx : indexes[target-elem]){
                    if(idx != i){
                        return {i, idx};
                    }
                }
            }
        }

        return {-1, -1};
    }
};