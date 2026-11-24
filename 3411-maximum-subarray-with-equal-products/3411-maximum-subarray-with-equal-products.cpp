
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int length = j - i + 1;

                if (length <= 2) {
                    ans = max(ans, length);
                    continue;
                }
                bool valid = true;
                for (int k = i; k <= j; k++) {
                    for (int l = k + 1; l <= j; l++) {
                        if (gcd(nums[k], nums[l]) != 1) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) {
                        break;
                    }
                }
                if (valid) {
                    ans = max(ans, length);
                }
            }
        }

        return ans;
    }
};
