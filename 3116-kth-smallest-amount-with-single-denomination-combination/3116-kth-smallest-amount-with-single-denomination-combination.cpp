class Solution {
public:
    long long countAmounts(vector<int>& coins, long long x) {
        int n = coins.size();
        long long count = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            // yha per mask ka mtlb h possible susbsets kitne bna skte h jo ki 1
            // se lekar 2 ki powr n tk bna skte h
            long long l = 1;
            bool valid = true;
            long long bits = 0;

            for (int i = 0; i < n; i++) {
                // yha per hm bits counts krenge
                if (mask & (1 << i)) {
                    bits++;

                    l = l / gcd(l, 1LL * coins[i]) * coins[i];

                    if (l > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            // agar bits odd h to includion excduion ke case me odd pe add krte
            // h and even pe subtract
            if (bits & 1) {
                count += x / l;
            } else {
                count -= x / l;
            }
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        // Binary Search on answer ki range 1 se start hoke min of coins * k tk
        // jaegi
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        long long ans = -1;
        while (low <= high) {
            long long mid = (low) + (high - low) / 2;

            if (countAmounts(coins, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};