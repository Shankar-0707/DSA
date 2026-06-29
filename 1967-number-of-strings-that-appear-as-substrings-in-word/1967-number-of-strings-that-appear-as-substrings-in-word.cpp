class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string, int> mp;

        for(int i=0; i<word.length(); i++){
            string temp = "";
            for(int j=i; j<word.length(); j++){
                temp+=word[j];
                mp[temp]++;
            }
        }

        int ans = 0;

        for(int i=0; i<patterns.size(); i++){
            if(mp[patterns[i]] > 0) ans++;
        }

        return ans;
    }
};