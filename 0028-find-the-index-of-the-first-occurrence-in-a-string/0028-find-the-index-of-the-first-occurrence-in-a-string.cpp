class Solution {
public:

    void computeLPS(string &needle, vector<int>& LPS){
        int M = needle.length();

        int length = 0;
        int i=1;
        LPS[0] = 0;

        while(i<M){
            if(needle[i] == needle[length]){
                length++;
                LPS[i] = length;
                i++;
            }
            else{
                if(length != 0){
                    length = LPS[length-1];
                }else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int N = haystack.length();
        int M = needle.length();

        vector<int> LPS(M, 0);
        computeLPS(needle, LPS);

        int i=0; 
        int j=0;

        while(i<N){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }

            if( j == M ){
                return i-M;
            }else if(i < N && haystack[i] != needle[j]){
                if(j!=0){
                    j = LPS[j-1];
                }
                else{
                    i++;
                }
            }
        }

        return -1;
    }
};