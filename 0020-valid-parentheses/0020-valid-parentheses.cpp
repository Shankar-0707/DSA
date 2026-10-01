class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                if(ch == ')' && st.top() != '(') return false;
                if(ch == '}' && st.top() != '{') return false;
                if(ch == ']' && st.top() != '[') return false;
                else{
                    st.pop();
                }
            }
        }

        return st.size() == 0 ? true : false;
    }
};