class Solution {
public:
    vector<int> countBits(int n) {
        if( n == 0 ) return {0};
        if( n == 1 ) return {0, 1};

        vector<int> ans(n+1, 0);
        ans[0] = 0;
        ans[1] = 1;

        for(int i=2; i<=n; i++){
            bool odd = (i & 1) == 1 ? true : false;

            int prev = ans[i/2];

            ans[i] = prev + (odd ? 1 : 0);
        }

        return ans;
    }
};