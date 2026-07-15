class Solution {
public:
    void solve(vector<vector<int>>& image, int rows, int cols, int row, int col,
               int originalColor, int color) {
        // base case
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            return;

        int currColor = image[row][col];
        if (currColor != originalColor)
            return;

        image[row][col] = color;
        solve(image, rows, cols, row + 1, col, originalColor, color);
        solve(image, rows, cols, row - 1, col, originalColor, color);
        solve(image, rows, cols, row, col + 1, originalColor, color);
        solve(image, rows, cols, row, col - 1, originalColor, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int originalColor = image[sr][sc];

        if (originalColor == color)
            return image;
        int rows = image.size();
        int cols = image[0].size();

        int row = sr;
        int col = sc;

        solve(image, rows, cols, row, col, originalColor, color);
        return image;
    }
};