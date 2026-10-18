class Solution {
public:
    typedef long long ll; // taki baar baar long long na likhna pde
    ll MOD = 1e9 + 7;

    vector<vector<ll>> PasTri;

    

    int solve(vector<int>& nums){
        int n = nums.size();
        if(n < 3) return 1;

        int root = nums[0];
        vector<int> left , right;

        for(int i=1; i<n; i++){
            if(nums[i] < root){
                left.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }

        ll x = solve(left);
        ll y = solve(right);
        ll z = PasTri[n-1][left.size()]; // Best way h nCr nikalne h 

        return (((x*y) % MOD) * z) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        PasTri.resize(n+1);

        for(int i=0; i<=n; i++){
            PasTri[i] = vector<ll> (i+1, 1);

            for(int j=1; j<i; j++){
                PasTri[i][j] = (PasTri[i-1][j] + PasTri[i-1][j-1]) % MOD;
            }
        }

        return (solve(nums) - 1) % MOD;
    }
};