class Solution {
public:
    int getSum(int a, int b) {
        // This requires Bit manipulations using XOR and carry approach 
        // basiclaly any sum is equal to -> sum by XOR without carry and Sum of carry 

        while(b != 0){
            int sum = a ^ b;
            int carry = (a & b ) << 1; // as this carry goes to next bit for further calculation
            b = carry;
            a = sum;
        }

        return a;
    }
};