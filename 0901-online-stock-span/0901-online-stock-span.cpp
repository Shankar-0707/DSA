class StockSpanner {
public:
    stack<pair<int,int>> s;

    StockSpanner() {
        
    }
    
    int next(int price){
        if(s.empty()){
            s.push({price, 1});
            return 1;
        }

        if(s.top().first > price){
            s.push({price, 1});
            return 1;
        }
        int span = 1;
        while(!s.empty() && s.top().first <= price){
            auto p = s.top();
            s.pop();
            span+= p.second;
        }

        s.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */