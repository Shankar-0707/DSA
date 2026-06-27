class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;

        bool flag = true; // positive h to true vrna false
        if( x < 0) flag = false;
        if(x == INT_MIN) return 0;
        x = abs(x);

        int ans = 0;
        while(x){
            int dig = x % 10;
            if( ans > INT_MAX/10) return 0;
            ans = ans*10 + dig;
            x = x /10;
        }

        if(flag) return ans;
        return (-1)*ans;
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;
        int temp = x;
        temp = reverse(temp);

        return temp == x;
    }
};