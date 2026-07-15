class Solution {
public:

    int GCD(int a, int b){
        if(a == 0) return b;
        if(b == 0) return a;

        if(a > b ){
            return GCD(a%b, b);
        }

        return GCD(a, b%a);
    }

    int gcdOfOddEvenSums(int n) {
        int oddNum = 1;
        int evenNum = 2;
        int oddSum = 0, evenSum = 0;

        for(int i=0; i<n; i++){
            oddSum+= oddNum;
            evenSum+= evenNum;
            oddNum+= 2;
            evenNum+= 2;
        }

        return GCD(oddSum, evenSum);
    }
};