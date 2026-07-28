class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();

        if (n == 1)
            return s; // base case

        // if length is even like
        // we can divide exactly two halves

        int total_index = n - 1;
        // babab total_index = 4
        // raccar total_index = 5

        if (total_index & 1) {
            // it means even length of string s
            int half_index = total_index / 2;
            string temp = s.substr(0, half_index + 1);
            sort(temp.begin(), temp.end());
            string ans = "";
            ans += temp;
            reverse(temp.begin(), temp.end());
            ans+= temp;
            return ans;
        }

        int half_index = total_index / 2;
        string temp = s.substr(0, half_index);
        sort(temp.begin(), temp.end());

        string ans = "";
        ans += temp;
        ans+= s[half_index];
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};