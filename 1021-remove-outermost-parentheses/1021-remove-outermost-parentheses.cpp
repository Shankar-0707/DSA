class Solution {
public:
    string removeOuterParentheses(string s) {
        // m phle sare primitve decomposition find krunga 
        int open = 0;
        int close = 0;
        vector<pair<int,int>> q;

        int n = s.length();
        int starting = -1;
        int closing = -1;

        for(int i=0; i<n; i++){
            if(open == 0) starting = i;


            if(s[i] == '(') open++;
            else{
                close++;
            }

            if(open == close){
                closing = i;
                q.push_back({starting, closing});
                open = 0;
                close = 0;
            }
        }

        for(auto p : q){
            cout << p.first << " , " << p.second << endl;
        }

        string ans = "";

        for(auto p : q){
            int first_index = p.first;
            int second_index = p.second;

            while(first_index+1 < second_index){
                ans.push_back(s[first_index+1]);
                first_index++;
            }
        }

        return ans;
    }
};