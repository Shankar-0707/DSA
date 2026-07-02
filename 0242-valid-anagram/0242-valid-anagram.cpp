class Solution {
public:
    bool isAnagram(string s, string t) {
        // method 1 - using unordered_map TC - O(n) Space - O(n)
        // method 2 - sort and compare 
        // mthod 3 - only 26 character will bne there so instead of making hashmap make a frequency array

        vector<int> freq(26, 0);

        for(auto i : s){
            freq[i - 'a']++;
        }
        for(auto i : t){
            freq[i-'a']--;
        }

        for(auto i : freq){
            if(i != 0) return false;
        }
        return true;
    }
};