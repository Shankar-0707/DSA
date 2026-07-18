class Solution {
public:

    void solve(vector<vector<int>>& image, int sr, int sc, int color, int originalColor, vector<vector<bool>> &visited){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;

        if(visited[sr][sc]) return;
        if(image[sr][sc] != originalColor) return;
        
        if(image[sr][sc] == originalColor && !visited[sr][sc]){
            image[sr][sc] = color;
            visited[sr][sc] = true;
        }

        solve(image, sr-1, sc, color, originalColor, visited);
        solve(image, sr+1, sc, color, originalColor, visited);
        solve(image, sr, sc-1, color, originalColor, visited);
        solve(image, sr, sc+1, color, originalColor, visited);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        solve(image, sr, sc, color, originalColor, visited);
        return image;
    }
};