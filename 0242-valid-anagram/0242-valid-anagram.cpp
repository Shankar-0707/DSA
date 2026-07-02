class Solution {
public:
    bool isAnagram(string s, string t) {
        // method 1 - using unordered_map TC - O(n) Space - O(n)
        // method 2 - sort and compare 
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};