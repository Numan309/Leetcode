class Solution {
public:
     int solve(int i,int j,vector<vector<int>>&dp)
     {
         if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0){
            return 0;
        }
       if(dp[i][j]!=-1) return dp[i][j];
        int up = solve(i-1,j,dp);
        int left = solve(i,j-1,dp);
        return dp[i][j] = up + left;
     }
    int solveTab(int m, int n) {
        // Create a 2D vector initialized to 0
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize the first row and first column to 1
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1; // There's only one way to reach any cell in the first column
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1; // There's only one way to reach any cell in the first row
        }
        
        // Fill the dp table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int up = dp[i - 1][j];   // Paths coming from above
                int left = dp[i][j - 1]; // Paths coming from the left
                dp[i][j] = up + left;
            }
        }
        
        // Return the number of unique paths to reach the bottom-right corner
        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n) {
        return solveTab(m, n);
    }
};