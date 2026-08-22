class Solution {
public:
    bool checkDivisibility(int n) {
        unordered_map<int,int> freq;
        int temp = n;
        while(temp){
            int dig = temp%10;
            // if(dig == 0) return false;

            freq[dig]++;
            temp = temp/10;
        }

        long long dig_sum = 0;
        long long dig_prod = 1;
        long long sum = 0;

        for(auto i : freq){
            dig_sum+= (i.first*i.second);
            int times = i.second;
            while(times){
                dig_prod*=i.first;
                times--;
            }
        }
        cout << dig_sum ;
        cout << dig_prod ;

        sum = dig_sum + dig_prod;

        if(n%sum == 0) return true;

        return false;
    }
};