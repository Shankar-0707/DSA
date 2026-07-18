class Solution {
public:

    int gcd(int a, int b){
        if(a == 0) return b;
        if(b == 0) return a;

        if(a > b){
            return gcd(a%b, b);
        }

        return gcd(a, b%a);
    }

    int findGCD(vector<int>& nums) {
        int smallest = INT_MAX;
        int largest = INT_MIN;

        for(int num : nums){
            smallest = min(smallest, num);
            largest = max(largest , num);
        }

        return gcd(smallest, largest);
    }
};