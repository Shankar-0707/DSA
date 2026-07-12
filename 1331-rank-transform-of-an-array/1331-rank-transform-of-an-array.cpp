class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int rank = 1;
        unordered_map<int, int> ranking;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        for (auto i : temp) {
            if (ranking[i] == 0) {
                ranking[i] = rank;
                rank++;
            }
        }

        vector<int> ans;
        for (auto i : arr) {
            ans.push_back(ranking[i]);
        }

        return ans;
    }
};