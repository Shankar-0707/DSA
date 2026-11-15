class Solution {
public:
    int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = arr[0];

        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }

        // prefixSum = [0,1,4,9]
        int evenCount = 1;
        int oddCount = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            if(prefixSum[i] % 2 == 0){
                // even h 
                ans = (ans + oddCount) % MOD;
                evenCount++;
            }
            else{
                // odd h to ans update 
                ans = (ans + evenCount) % MOD;
                oddCount++;
            }
        }

        return ans;
    }
};