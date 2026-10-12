class Solution {
public:
    int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);

        for(int num : nums){
            for(int bit = 0; bit < 32; bit++){
                if(num & (1 << bit)){
                    count[bit]++;
                }
            }
        }

        long long result = 0;

        while(k--){
            long long curr = 0;
            for(int bit = 0; bit < 32; bit++){
                if(count[bit] > 0){
                    count[bit]--;
                    curr = (curr | (1 << bit));
                }
            }

            result = (result + (curr * curr)) % MOD;
        }

        return result;
    }
};