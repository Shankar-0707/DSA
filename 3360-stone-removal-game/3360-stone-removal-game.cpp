class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;

        bool ans = false ;
        int num = 10;

        while(n >= num){
            n-= num;
            num--;
            ans = !ans;
        }

        return ans;


    }
};