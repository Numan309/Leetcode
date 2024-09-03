class Solution {
public:
    // Define a 2D vector for memoization
    vector<vector<int>> memo;
    
    // Function to compute the minimum path sum using recursion and memoization
    int solve(int i, int j, vector<vector<int>>& triangle, int n) {
        // Base case: when reaching the last row
        if (i == n - 1) return triangle[i][j];
        
        // Check if the result is already computed and stored in the memo table
        if (memo[i][j] != -1) return memo[i][j];
        
        // Recursively compute the minimum path sum for the two possible moves
        int down = solve(i + 1, j, triangle, n);
        int diagonal = solve(i + 1, j + 1, triangle, n);
        
        // Include the current cell's value and store the result in the memo table
        memo[i][j] = triangle[i][j] + min(down, diagonal);
        return memo[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Initialize memoization table with -1 (indicating that no value is computed yet)
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        
        // Start the recursion from the top of the triangle
        return solve(0, 0, triangle, n);
    }
};
