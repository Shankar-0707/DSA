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
            int a = 1; int b = n-2;
            while(a <= b){
                int mid = a + (b-a)/2;
                if(nums[mid] == target){
                    found = true;
                    break;
                }
                else if(target > nums[mid]){
                    a = mid+1;
                }
                else{
                    b = mid-1;
                }
            }

            if(!found){
                ans.push_back(i);
            }
        }

        return ans;
    }
};