class Solution {
public:
    int reverseBits(int n) {
        int temp = n;
        vector<int> binary(32, 0);

        for(int i=0; i<32; i++){
            // 32 times
            int bit = temp & 1;
            binary[i] = bit;
            temp = temp >> 1;
        }

        long long num = 0;
        for(auto bit : binary){
            num = (num << 1) | bit;
        }
        return num;
    }
};