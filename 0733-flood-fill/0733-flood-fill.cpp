class Solution {
public:
    void DFS(int i, int j, int initialColor, int newColor, vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();

        // Boundary checks and color check
        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != initialColor) return;

        // Update the color
        image[i][j] = newColor;

        // Explore the four possible directions
        DFS(i - 1, j, initialColor, newColor, image); // Up
        DFS(i + 1, j, initialColor, newColor, image); // Down
        DFS(i, j - 1, initialColor, newColor, image); // Left
        DFS(i, j + 1, initialColor, newColor, image); // Right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor != color) { // Make sure we only start DFS if color change is needed
            DFS(sr, sc, initialColor, color, image);
        }
        return image;
    }
};
