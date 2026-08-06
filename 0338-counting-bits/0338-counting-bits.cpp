class Solution {
public:

    int getSetBits(int n){
        int ans = 0;
        while(n){
            int bit = n&1;
            if(bit) ans++;
            n = n >> 1;
        }
        return ans;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for(int i=0; i<=n; i++){
            int no_bits = getSetBits(i);
            ans[i] = no_bits;
        }

        return ans;
    }
};