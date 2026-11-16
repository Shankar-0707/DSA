class Solution {
public:

    string newDigSum(string temp){
        int sum = 0;

        for(int i=0; i<temp.length(); i++){
            char ch = temp[i];
            int chInt = ch - '0';
            sum+= chInt;
        }

        string ans = to_string(sum);
        return ans;
    }

    string digitSum(string s, int k) {
        if(s.length() <= k) return s;
        int n = s.length();
        string ans = "";
        int i=0;


        while(i < n){
            string temp = "";
            int count = 0;
            while(count < k && i < n){
                temp+= s[i];
                i++;
                count++;
            }

            ans+= newDigSum(temp);
        }

        if(ans.size() > k){
            return digitSum(ans, k);
        }

        return ans;
       
    }
};