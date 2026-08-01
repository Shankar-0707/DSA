class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int curr = prices[0]; // ye m man leta hu ki mera current stock h 

        for(int i=1; i<n; i++){
            if(prices[i] <= curr){
                curr = prices[i];
            }
            else{
                profit = max(profit, prices[i] - curr);
            }
        }
        return profit;
    }
};