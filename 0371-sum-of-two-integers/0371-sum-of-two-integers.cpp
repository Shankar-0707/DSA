class Solution {
public:
    int getSum(int a, int b) {
        // sum = sum wihtout carry + carry 
        while(b!= 0){
            int sum = (a ^ b);
            int carry = (a & b) << 1;
            a = sum;
            b = carry;
        }

        return a;
    }
};