class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> indexes;

        for(int i=0; i<n; i++){
            int elem = nums[i];

            if(indexes.find(target-elem) != indexes.end()){
                // mtlb is ke liye phle ek index aa chuka h asa 
                return {indexes[target-elem], i};
                // isse i kbhi us elemnet ke index ke equal bhi nhi hoga so same element twice nhi aaenge 
            }
            else{
                indexes[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};