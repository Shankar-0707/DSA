class Solution {
public:
    int t[301][5001];
    int solve(int amount, vector<int>& coins, int index){
        // base case
        if(index >= coins.size() || amount < 0) return 0;

        if(amount == 0) return 1;

        if(t[index][amount] != -1) return t[index][amount];
        int ans = 0;
        for(int i=index; i<coins.size(); i++){
            ans+= solve(amount - coins[i], coins, i);
        }

        return t[index][amount] = ans;
    }

    int change(int amount, vector<int>& coins) {
        // agr m array ko sort krdu ya nhi krta suppose lekin agar hm ek index per aa gye to uske phle wale vapas se nhi le skte h 

        // ab aati h baat dp ki hm etree diagram me dheka ki ek index per dobara se agar vhi amouynt a jaye to hm uska answer already niakl chuke honge to use jhi use krlenge 
        memset(t, -1, sizeof(t));
        return solve(amount, coins, 0);
    }
};