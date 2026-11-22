class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int i = 0;
        bool ans = true;
        while(i<n && s[i] == 'a'){
            i++;
        }

        while(i<n){
            if(s[i] == 'a'){
                ans = false;
                break;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};