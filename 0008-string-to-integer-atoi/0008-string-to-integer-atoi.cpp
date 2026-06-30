class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0; // to traverse on string

        // remove whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // check sign kya h
        int sign = 1; // true -> positive
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // remove leading zeroes
        while (i < n && s[i] == '0') {
            i++;
        }
        long long ans = 0;
        // ab yha na hi to sign h na hi whitespaces na hi leading zeroes
        while (i < n && isdigit(s[i])) {
            char ch = s[i];
            int num = ch - '0';

            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && (num > (sign == 1 ? 7 : 8)))) {
                if (sign == -1)
                    return INT_MIN;
                return INT_MAX;
            } else {
                ans = ans * 10 + num;
            }

            i++;
        }

        if (sign == -1)
            return -(long long)ans;

        return (int)ans;
    }
};