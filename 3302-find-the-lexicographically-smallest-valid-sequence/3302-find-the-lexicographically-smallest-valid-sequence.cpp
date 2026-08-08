class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> rightMatchCount(n+1, 0);
        int rightCount = 0;

        int i = n-1;
        int j = m-1;
       
        while(i >= 0){
            if(j>= 0 && word1[i] == word2[j]){
                rightCount++;
                j--;
            }
           

            rightMatchCount[i] = rightCount;
            i--;
        }

        

        bool ability = true;

        vector<int> ans(m,0);
        int start = 0;

        i=0;
        j=0;

        while(i < n && j < m){
            if(word1[i] == word2[j]){
                // best case 
                ans[start++] = i;
                i++;
                j++;
            }
            else{
                if(ability){
                    // checkk kro ki agar hm ise change krde to kya aage hmare paaas required stuff h agar h to hm ise consider krlenge 
                    int req = m-j-1;
                    if(rightMatchCount[i+1] >= req){
                        // hn m ise change kr skta hu 
                        ability = false;
                        ans[start++] = i;
                        i++;
                        j++;
                    }
                    else{
                        i++;
                    }
                }
                else{
                    i++;
                }
            }
        }

        if(j < m){
            return {};
        }

        return ans;
    }
};