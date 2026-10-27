class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<string>> grid(m , vector<string>(n , "#"));

        for(int i=0; i<n; i++){
            grid[0][i] = ".";
        }

        for(int i=0; i<m; i++){
            grid[i][n-1] = ".";
        }

        vector<string> ans;

        for(int i=0; i<m; i++){
            string temp = "";
            for(int j=0; j<n; j++){
                temp+= grid[i][j];
            }

            ans.push_back(temp);
        }

        return ans;
    }
};