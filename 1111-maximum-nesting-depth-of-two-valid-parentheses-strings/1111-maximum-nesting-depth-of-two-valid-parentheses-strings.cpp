class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // hmare paas 2 hi grpup h to hr ek element either goes to grp 0 and grp 1 
        // basically score % 2 

        int n = seq.length();
        int score = 0;
        vector<int> ans(n, -1);

        for(int i=0; i<n; i++){
            if(seq[i] == '('){
                score++;
                ans[i] = score % 2;
            }
            else{
                ans[i] = score % 2;
                score--;
            }
        }

        return ans;
    }
};