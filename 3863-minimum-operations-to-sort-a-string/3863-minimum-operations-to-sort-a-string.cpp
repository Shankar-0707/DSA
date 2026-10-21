class Solution {
public:
    int minOperations(string s) {
        string temp = s;
        sort(temp.begin(), temp.end());
        int n = s.length();

        // Best case agar dono phle se hi sorted ho 
        if(s == temp) return 0;

        if(n == 2) return -1;

        char mn = 'z';
        char mx = 'a';

        for(int i=0; i<n; i++){
            char curr = s[i];
            if(curr > mx){
                mx = curr;
            }
            if(curr < mn){
                mn = curr;
            }
        }

        // Second best case 
        if(mn == s[0] || mx == s[n - 1]) return 1;

        char mx_mid = *max_element(s.begin()+1, s.end()-1);
        char mn_mid = *min_element(s.begin()+1, s.end()-1);

        if(s[0] > mx_mid && s[n-1] < mn_mid) return 3;

        return 2;
    }
};