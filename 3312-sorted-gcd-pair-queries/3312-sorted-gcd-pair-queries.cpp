class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> divisorFreq(maxVal + 1, 0);

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int j = 1; j * j <= num; j++) {
                if (num % j == 0) {
                    divisorFreq[j]++;
                    if (num / j != j) {
                        divisorFreq[num / j]++;
                    }
                }
            }
        }

        vector<long long> pairsWithGCD(maxVal + 1, 0);

        for (int i = maxVal; i >= 1; i--) {
            long long count = divisorFreq[i];

            long long countPairs = count * (count - 1) / 2;
            pairsWithGCD[i] = countPairs;

            // correction time
            for (int mul = 2 * i; mul <= maxVal; mul += i) {
                pairsWithGCD[i] -= pairsWithGCD[mul];
            }
        }

        vector<long long> prefixCountGCD(maxVal + 1, 0);

        for (int g = 1; g <= maxVal; g++) {
            prefixCountGCD[g] = prefixCountGCD[g - 1] + pairsWithGCD[g];
        }

        vector<int> result;

        for (long long idx : queries) {
            int l = 1;
            int r = maxVal;
            int temp = 1;

            while (l <= r) {
                int mid_gcd = l + (r - l) / 2;

                if (prefixCountGCD[mid_gcd] > idx) {
                    temp = mid_gcd;
                    r = mid_gcd - 1;
                } else {
                    l = mid_gcd + 1;
                }
            }

            result.push_back(temp);
        }
        return result;
    }
};