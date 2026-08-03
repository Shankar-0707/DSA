class Solution {
public:
    int solve(vector<int>& stoneValue, int i, vector<int>& dp) {
        if (i >= stoneValue.size())
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int one = stoneValue[i] - solve(stoneValue, i + 1, dp);
        int two = INT_MIN;
        if (i + 1 < stoneValue.size()) {
            two = stoneValue[i] + stoneValue[i + 1] -
                  solve(stoneValue, i + 2, dp);
        }

        int three = INT_MIN;
        if (i + 2 < stoneValue.size()) {
            three = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] -
                    solve(stoneValue, i + 3, dp);
        }

        return dp[i] = max({one, two, three});
    }

    int solve2(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int i = 0;
        vector<int> dp(n + 3, 0);

        for (int i = n - 1; i >= 0; i--) {
            int ans = stoneValue[i] - dp[i + 1];

            if (i + 1 < n) {
                ans = max(ans, stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            }

            if (i + 2 < n) {
                ans = max(ans, stoneValue[i] + stoneValue[i + 1] +
                                   stoneValue[i + 2] - dp[i + 3]);
            }

            dp[i] = ans;
        }

        return dp[0];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int i = 0;
        vector<int> dp(n + 1, INT_MIN);
        int ans = solve2(stoneValue);

        if (ans == 0)
            return "Tie";
        if (ans < 0)
            return "Bob";

        return "Alice";
    }
};