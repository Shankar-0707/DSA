class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2) return n;

        int ans = 1;

        while(ans <= n){
            ans*=2;

            // n ki kisi bhi balue ki highest answer 2 ki power uske nearest big one tk hi ja skta h 
        }

        return ans;
    }
};