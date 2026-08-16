class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> count(3, 0);

        for(int i=0; i<stones.size(); i++){
            int rem = stones[i] % 3 ;
            count[rem]++;
        }

        // case 1 ki agar count of 0 even ho it means ki vo answewr pe effect nhi dalega
        if(count[0] % 2 == 0){
            return count[1] > 0 && count[2] > 0;
        }

        return abs(count[1] - count[2]) > 2;
    }
};