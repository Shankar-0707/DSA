class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> freq(26, 0);
        for(auto i : word){
            freq[i-'a']++;
        }

        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());;
        int ans = 0;
        int push = 1;
        for(int i=0; i<freq.size(); i++){
            if(i != 0 && i % 8 == 0){
                push++;
            }

            ans+= freq[i] * push;

        }

        return ans;
    }
};