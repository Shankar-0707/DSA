class Solution {
public:
    int balanceIndex(string& s, int idx) {
        int bal = 0;

        for (int i = idx; i < s.length(); i++) {
            if (s[i] == '(')
                bal++;
            else {
                bal--;
            }

            if (bal == 0)
                return i; // it means this is the balanc ) for idx (
        }

        return -1;
    }

    int solve(string& s, int start, int end) {
        if (start + 1 == end) {
            return 1;
        }

        // find the matching of the first (
        int matchingIdx = balanceIndex(s, start);

        if (matchingIdx == end) {
            // nested struture h iska matlb
            return 2 * solve(s,start + 1, end - 1);
        }

        return solve(s,start, matchingIdx) + solve(s,matchingIdx + 1, end);
    }

    int scoreOfParentheses(string s) {
        // int start = 0;
        // int end = s.length() - 1;

        // return solve(s, start, end);


        // Method 2 using Stack 
        // stack<int> st;
        // st.push(0);

        // for(int i=0; i<s.length(); i++){
        //     if(s[i] == '('){
        //         st.push(0);
        //     }
        //     else{
        //         if(st.top() == 0){
        //             int score = 1;
        //             st.pop();
        //             st.top() += score;
        //         }
        //         else{
        //             int score = 2* st.top();
        //             st.pop();
        //             st.top() += score;
        //         }
        //     }
        // }

        // return st.top();

        // Method 3 using depth approach 

        int depth = 0;
        int answer = 0;
        char prev = 'a';
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '(') depth++;
            else{
                if(prev == '('){
                    answer+= pow(2,depth-1);
                }
                depth--;
            }

            prev = s[i];
        }


        return answer;
    }
};