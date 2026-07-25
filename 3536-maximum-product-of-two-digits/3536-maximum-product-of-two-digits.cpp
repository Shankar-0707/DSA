class Solution {
public:
    int maxProduct(int n) {       
        priority_queue<int, vector<int>, greater<int>> pq;

        while (n) {
            int dig = n % 10;
            pq.push(dig);

            if(pq.size() > 2){
                pq.pop();
            }

            n/=10;
        }

        int top = pq.top();
        pq.pop();
        int second = pq.top();

        return top*second;
    }
};