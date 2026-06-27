class Solution {
public:

    void all_next(vector<int>& heights, vector<int>& next){
        stack<int> s;
        s.push(-1);
        int n = heights.size();

        for(int i = n-1; i>=0; i--){
            int currElement = heights[i];

            while(s.top() != -1 && heights[s.top()] >= currElement){
                s.pop();
            }

            next.push_back(s.top() == -1 ? n: s.top());
            s.push(i);
        }
    }

       void all_prev(vector<int>& heights, vector<int>& prev){
        stack<int> s;
        s.push(-1);
        int n = heights.size();

        for(int i = 0; i<n; i++){
            int currElement = heights[i];

            while(s.top() != -1 && heights[s.top()] >= currElement){
                s.pop();
            }

            prev.push_back(s.top());
            s.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> next;
        vector<int> prev;
        all_next(heights, next);
        reverse(next.begin(), next.end());
        all_prev(heights, prev);

        int ans = INT_MIN;

        for(int i =0; i<heights.size(); i++){
            int width = next[i] - prev[i] - 1;
            int height = heights[i];
            int area = width * height;
            ans = max(ans, area);
        }

        return ans;

    }
};