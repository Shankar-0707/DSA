class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n+1, 0);
        int cheapest_price = INT_MAX;
        for(auto v : items){
            int f = v[0];
            int p = v[1];
            freq[f]++;
            cheapest_price = min(cheapest_price, p);
        }

        vector<int> factorSum(n+1, 0);
        for(int f=1; f<=n; f++){
            for(int k=f; k<=n; k+=f){
                factorSum[f] += freq[k];
            }
        }

        vector<pair<int,int>> units;
        for(auto v : items){
            int f = v[0];
            int p = v[1];

            int count = factorSum[f] - 1;

            if(count > 0 && p < 2LL* cheapest_price){
                units.push_back({p, count});
            }
        }

        sort(units.begin(), units.end());

        int result = 0;

        for(auto [price, factorCount] : units){
            int k = min(factorCount, budget / price);
            budget -= k * price;
            result += 2*k;
        }

        result+= budget / cheapest_price;
        return result;
    }
};