class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        int activeCount = count(s.begin(), s.end(), '1');

        vector<int> inActiveBlocks;
        int i = 0;

        while(i<n){
            if(s[i] == '0'){
                int start = i;
                while(s[start] == '0' && start < n){
                    start++;
                }
                inActiveBlocks.push_back(start-i);
                i = start;
            }
            else{
                i++;
            }
        }

        int maxInActiveBlock = 0;

        for(int i=1; i<inActiveBlocks.size(); i++){
            maxInActiveBlock = max(maxInActiveBlock, inActiveBlocks[i] + inActiveBlocks[i-1]);
        }

        return maxInActiveBlock + activeCount;
    }
};