class Solution {
public:
    string smallestSubsequence(string s) {
        // making an array frequency to store all the frequency of the chanracters 
        vector<int> freq(26, 0);

        // making an visited array to check which element is visited and which is not 
        vector<bool> visited(26, false);

        // make and stackl to store elements 
        stack<char> st;

        for(auto c : s){
            freq[c-'a']++;
        }

        for(auto c : s){
            // sbse phle uski ek freq ko km krdo iska mtlb vo ek baar use ho gya h abhi 
            freq[c-'a']--;

            // ab check kro ki kya vo already stack me h agar h iska mtlb h ki vo abhi tk hmare answer ka part h hme use apas use nhi krn kyoki question me bola h exactly once 
            if(visited[c-'a']) continue;

            // agar nhi h to use uski correct position tk le jayenge 

            while(!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0){
                // iska mtlb jb tk stack empty nhi hota and jb tk koi bda element uske top pe bhtha h jiski freq abhi bhi 0 se bdi h mtlb ki vo baad me bhi mil skta h to hme lexographically bnana h isiliye hm bde ko target krre h or freq bhi check krre h 
                visited[st.top()-'a'] = false;
                st.pop();
            }

            st.push(c);
            visited[c-'a'] = true;
        }

        string ans = "";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};