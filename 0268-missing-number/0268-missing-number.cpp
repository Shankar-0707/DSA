class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR = 0;
        int n = nums.size();
        for(int i=0; i<=n; i++){
            XOR ^= i;
        }

        for(auto i : nums){
            XOR ^= i;
        }

        return XOR;
    }
};