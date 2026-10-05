class Solution {
public:
    int balanceIndex(string& s, int idx) {
        int bal = 0;

        for (int i = idx; i < s.length(); i++) {
            if (s[i] == '(')
                bal++;
            else {
                bal--;
            }

            if (bal == 0)
                return i; // it means this is the balanc ) for idx (
        }

        return -1;
    }

    int solve(string& s, int start, int end) {
        if (start + 1 == end) {
            return 1;
        }

        // find the matching of the first (
        int matchingIdx = balanceIndex(s, start);

        if (matchingIdx == end) {
            // nested struture h iska matlb
            return 2 * solve(s,start + 1, end - 1);
        }

        return solve(s,start, matchingIdx) + solve(s,matchingIdx + 1, end);
    }

    int scoreOfParentheses(string s) {
        int start = 0;
        int end = s.length() - 1;

        return solve(s, start, end);
    }
};