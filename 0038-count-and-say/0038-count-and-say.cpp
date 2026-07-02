class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        int iteration = 1;

        while(iteration < n){
            string temp = "";
            int i=1;
            int count = 1;
            while(i < ans.length()){
                if(ans[i] == ans[i-1]){
                    count++;
                    i++;
                }
                else{
                    temp+= (count + '0');
                    temp+= ans[i-1];
                    i++;
                    count = 1;
                }
            }

            temp+= (count + '0');
            temp+= ans[ans.length()-1];

            ans = temp;
            iteration++;
        }

        return ans;
    }
};