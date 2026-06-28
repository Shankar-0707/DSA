class Solution {
public:

    void next(vector<int>& heights, vector<int>& all_next){
        stack<int> s;
        s.push(-1);
        int n = heights.size();

        for(int i = n-1; i>=0; i--){
            int elem = heights[i];
            while(s.top() != -1 && heights[s.top()] >= elem){
                s.pop();
            }

            all_next[i] = s.top() == -1 ? n : s.top();
            s.push(i);
        }
    }

    void prev(vector<int>& heights, vector<int>& all_prev){
        stack<int> s;
        s.push(-1);
        int n = heights.size();
        for(int i=0; i<n; i++){
            int elem = heights[i];
            while(s.top() != -1 && heights[s.top()] >= elem){
                s.pop();
            }

            all_prev[i] = s.top();
            s.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        vector<int> all_next(n, -1);
        vector<int> all_prev(n, -1);

        next(heights, all_next);
        prev(heights, all_prev);
        
        for(int i=0; i<n; i++){
            int width = all_next[i] - all_prev[i] - 1;
            long long area = heights[i]*width;
            if(area > ans){
                ans = area;
            }
        }

        return ans;
    }
};