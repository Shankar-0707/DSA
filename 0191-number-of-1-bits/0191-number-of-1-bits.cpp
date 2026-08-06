class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while(n){
            int bit = n & 1; // As this operator tells us that the number if 1 then its and with 1 is also set 
            if(bit) ans++;

            n = n >> 1; // so that we can go to next bit and caluclate whether i is set or not 
        }

        return ans;
    }
};