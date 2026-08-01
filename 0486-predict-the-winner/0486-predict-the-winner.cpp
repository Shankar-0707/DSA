class Solution {
public:
    bool solve(vector<int>& nums, int score1, int score2, int i, int j,
               bool turn) {
        if (i > j) {
            if (score1 >= score2)
                return true;

            return false;
        }

        if (turn) {
            // player1 choose krega do option h uske paas

            bool one = solve(nums, score1 + nums[i], score2, i + 1, j, !turn);
            bool two = solve(nums, score1 + nums[j], score2, i, j - 1, !turn);

            return one || two;
        }

        bool one = solve(nums, score1 , score2 + nums[i], i + 1, j, !turn);
        bool two = solve(nums, score1 , score2 + nums[j], i, j - 1, !turn);

        return one && two; // uyha per && isiliye kyoki player2 agar ek me bhi jeet gya to vo vhi move choose krega obv isiliye player1 ko jitne ke liye player2 ko dono move me harnaa pdega 
    }

    bool predictTheWinner(vector<int>& nums) {
        int score1 = 0;
        int score2 = 0;

        bool turn = 1; // 1 -> player1 , 0 -> player2

        int n = nums.size();
        int i = 0;
        int j = n - 1;

        return solve(nums, score1, score2, i, j, turn);
    }
};