class Solution {
public:
    long long limit;
    long long C(int n, int r) {
        if (r > n)
            return 0;

        r = min(r, n - r);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {

            long long num = n - r + i;
            long long den = i;

            long long g = gcd(num, den);
            num /= g;
            den /= g;

            g = gcd(ans, den);
            ans /= g;
            den /= g;

            if (ans > limit / num)
                return limit;

            ans *= num;

            if (den != 1)
                ans /= den;

            if (ans >= limit)
                return limit;
        }

        return ans;
    }

    long long countPermutation(vector<int>& freq) {

        int total = accumulate(freq.begin(), freq.end(), 0);

        long long ans = 1;

        for (int i = 0; i < 26; i++) {

            if (freq[i] == 0)
                continue;

            long long ways = C(total, freq[i]);

            if (ans > limit / ways)
                return limit;

            ans *= ways;

            if (ans >= limit)
                return limit;

            total -= freq[i];
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        limit = k;
        // Step 1 Frequency ko count kro
        int n = s.length();

        vector<int> freq(26, 0);
        for (auto ch : s) {
            freq[ch - 'a']++;
        }

        // half frequencies bnao
        for (auto& f : freq) {
            f /= 2;
        }
        string middle_character = "";
        if (n & 1) {
            middle_character += s[n / 2];
        }

        int half = accumulate(freq.begin(), freq.end(), 0);

        string ans = "";
        while (half--) {
            bool found = false;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (freq[ch - 'a'] == 0)
                    continue;
                else {
                    freq[ch - 'a']--;

                    long long count = countPermutation(freq);
                    if (count >= k) {
                        ans += ch;
                        found = true;
                        break;
                    } else {
                        k -= count;

                        freq[ch - 'a']++;
                    }
                }
            }
            if (!found)
                return "";
        }

        string final = "";
        final += ans;
        if (middle_character != "") {
            final += middle_character;
        }
        reverse(ans.begin(), ans.end());
        final += ans;
        return final;
    }
};