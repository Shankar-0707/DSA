class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> XOR;

        // making pair of all Unique XOR that can be made 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int temp = nums[i] ^ nums[j];
                XOR[temp]++;
            }
        }

        // Now taking XOR with each pair and with each elements once again 
        unordered_map<int,int> ans;
        for(auto it : XOR){
            for(int z = 0; z<n; z++){
                int temp = it.first ^ nums[z];
                ans[temp]++;
            }
        }

        return ans.size();
    }
};