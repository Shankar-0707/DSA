class Solution {
public:
    int smallestNumber(int n, int t) {

        while (true) {
            int temp = n;
            int sec = temp;
            int prod = 1;
            while(temp){
                int dig = temp % 10;
                prod *= dig;
                temp /= 10;
            }
            if(prod % t == 0) return sec;

            n++;
        }

        return -1;
    }
};