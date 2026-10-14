class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string curr = "";

        // num -> number of digits 
        // sum -> sum of digits 

        while(true){
            if(sum >= 9){
                curr+= "9";
                sum-= 9;
            }
            else{
                // iska mtlb sum less than h 9 ke 
                curr+= to_string(sum);
                sum = 0;
            }


            // edge cases 
            if(curr.size() == num) break;
        }

        if(sum > 0) return "";
        return curr;
    }
};