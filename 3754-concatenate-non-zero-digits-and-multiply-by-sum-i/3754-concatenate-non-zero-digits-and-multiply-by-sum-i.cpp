class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;
        string temp = "";

        while(n){
            long long dig = n % 10;
            if( dig != 0){
                sum+= dig;
                // x = x*10 + dig;
                temp+= (dig+'0');
            }

            n = n/10;
        }
        reverse(temp.begin(), temp.end());

        for(auto i : temp){
            x = x*10 + (i-'0');
        }

        return sum*x;
    }
};