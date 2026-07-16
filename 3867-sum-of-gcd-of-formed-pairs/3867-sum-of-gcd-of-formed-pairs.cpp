class Solution {
public:

    long long GCD(long long a, long long b){
        if(a == 0) return b;
        if( b == 0 ) return a;

        if(a > b){
            return GCD(a%b, b);
        }

        return GCD(a, b%a);
    }

    long long max(long long a, long long b){
        return a > b ? a : b;
    }

    long long gcdSum(vector<int>& nums) {
        long long size = nums.size();
        long long maxi = INT_MIN;

        vector<long long> mx(size, 0);

        for(int i=0; i<size; i++){
            maxi = max(maxi, nums[i]);
            mx[i] = maxi;
        }

        // yha per meri mx array ready h 

        vector<long long> prefixGCD(size, 0);

        for(int i=0; i<size; i++){
            long long a = nums[i];
            long long b = mx[i];
            long long gcd = GCD(a,b);
            prefixGCD[i] = gcd;
        }

        sort(prefixGCD.begin(), prefixGCD.end());

        int m = 0;
        int n = size-1;
        long long ans = 0;
        while(m < n){
            long long a = prefixGCD[m];
            long long b = prefixGCD[n];

            ans+= GCD(a, b);

            m++;
            n--;
        }

        return ans;
    }
};