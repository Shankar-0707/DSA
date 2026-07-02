class Solution {
public:
    unordered_map<string, vector<pair<char,int>> > mp;  // string -> unique pair ka first elem digit pair ka second elem usiki frequency 


    void helper1(string s){
        if(mp.find(s) != mp.end()) return;

        // yha per map create krenge 
        int count = 1;
        int i=1;
        int n = s.length();
        while(i<n){
            if(s[i] == s[i-1]){
                count++;
                i++;
            }
            else{
                // yha per break aayega 
                mp[s].push_back({s[i-1], count});
                count = 1;
                i++;
            }
        }

        if(count){
            mp[s].push_back({s[n-1], count});
        }

        return;
    }

    void helper2(string &ans){
        // ab yha per hm ek new string bnayenge 
        auto arr =  mp[ans];
        ans = "";

        for(auto p : arr){
            // first place pe freq aayegi yani arr ke pair ke second value 
            int freq = p.second;
            ans+= (freq + '0');

            char dig = p.first;           
            ans+= (dig);
        }
        
    }

    string countAndSay(int n) {
        string ans = "1";
        int iteration = 1;
        

        while(iteration < n){
            helper1(ans);
            helper2(ans);
            iteration++;
        }

        return ans;
    }
};