class Solution {
public:
    string removeDuplicateLetters(string s) {
        // frequency array to track the frequency of each element
        vector<int> freq(26,0);

        // visited array to track which element is in the stack and which is not 
        vector<bool> visited(26, false);

        // stack 
        stack<char> st;

        for(auto i : s){
            freq[i-'a']++;
        }

        for(auto i : s){
            // sbse phle to aate hi freq ko ek km krdo 
            freq[i-'a']--;

            // ab check kro ki agar vo already stack me h to use mt aane do 
            if(visited[i-'a']) continue;

            // ab iska mtlb h ki vo stack me nhi aaya ab uski position dhekte h ki vo kha aata
            while(!st.empty() && st.top() > i && freq[st.top() - 'a'] > 0){
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(i);
            visited[i-'a'] = true;
        }

        // answer ko nikalo stack se 
        string ans = "";

        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};