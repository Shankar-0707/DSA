class Solution {
public:
    int t[501][501];

    int solve(int l, int r, vector<int>& prefix){
        if(l >= r){
            return 0; // no score can be obtain from here
        }

        if(t[l][r] != -1) return t[l][r];
        int score = 0;
        for(int mid = l; mid < r; mid++){
            int left = prefix[mid] - (l-1 >= 0 ? prefix[l-1] : 0);
            int right = prefix[r] - prefix[mid];

            if(left < right){
                score = max(score, left + solve(l, mid, prefix));
            }
            else if(left > right){
                score = max(score, right + solve(mid+1, r, prefix));
            }
            else{
                // alice can choose both so we take both the outcomes
                score = max({score, left + solve(l, mid, prefix), right + solve(mid+1, r, prefix)});
            }
        }

        return t[l][r] = score;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n, 0); // baar baar accumulate krne se acha h ki hm prefix arrayu bnaye
        prefix[0] = stoneValue[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + stoneValue[i];
        }

        memset(t, -1, sizeof(t));

        return solve(0, n-1, prefix);
    }
};