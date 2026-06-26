class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int>
            mp; // phla wala cumSum dusre wala uski freq ya count
        mp[0] = 1;

        long long cumSum = 0;
        long long validLeftPoints = 0;
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                validLeftPoints += mp[cumSum];
                cumSum++;

            } else {
                cumSum--;
                validLeftPoints -= mp[cumSum];
            }
            ans += validLeftPoints;

            mp[cumSum]++;
        }

        return ans;
    }
};