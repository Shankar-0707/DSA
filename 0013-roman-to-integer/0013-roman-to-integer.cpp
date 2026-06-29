class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {
            {'I',1}, {'V',5}, {'X', 10}, {'L',50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int ans = 0;

        // simple if current value is less than next one then subtract the current one as it automatic get merged in next one like 
        // IV = -1 + 5 = 4

        for(int i=0; i<s.length(); i++){
            if(i+1 < s.length() && values[s[i]] < values[s[i+1]]){
                ans-= values[s[i]];
            }
            else{
                ans+=values[s[i]];
            }
        }

        return ans;
    }
};