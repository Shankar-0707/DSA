class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int count = 0;
        int insertions = 0;
        int i=0;

        while(i<n){
            if(s[i] == '('){
                count++;
                i++;
            }
            else{
                // close brakcte h 
                if(count > 0){
                    count--;
                }
                else{
                    insertions++;
                }

                if(i+1 < n && s[i+1] == ')'){
                    i+=2;
                }
                else{
                    insertions++;
                    i+=1;
                }
            }
        }

        return insertions + 2*count;
    }
};