class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp; // To store the frequencies of each character
        int left = 0;
        int ans = 0;

        for(int right = 0; right < n; right++){
            char ch = s[right];
            mp[ch]++;

            // if the frequency of this character is more than 2 we just gradually decrease the frequencies from left until it comes at most 2 
            while(left < right && mp[ch] > 2){
                mp[s[left]]--;
                left++;
            }

            // this is the valid substring so we compute the answer here 
            ans = max(ans, right-left+1);
        }

        return ans;
        
    }
};