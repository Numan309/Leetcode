class Solution {
public:
    int solve(vector<int> &obstacles, int curr_lane, int pos, vector<vector<int>>& dp) {
        int n = obstacles.size() - 1;
        // Base case
        if (pos == n) {
            return 0;
        }
        if (dp[curr_lane][pos] != -1) return dp[curr_lane][pos];

        if (obstacles[pos + 1] != curr_lane) {
            dp[curr_lane][pos] = solve(obstacles, curr_lane, pos + 1, dp);
        } else {
            // Obstacle present, we have to jump side
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++) {
                if (curr_lane != i && obstacles[pos] != i) {
                    ans = min(ans, 1 + solve(obstacles, i, pos, dp));
                }
            }
            dp[curr_lane][pos] = ans;
        }
        return dp[curr_lane][pos];
    }

    int solveTab(vector<int> &obstacles) {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int pos = n - 1; pos >= 0; pos--) {
            for (int curr_lane = 1; curr_lane <= 3; curr_lane++) {
                if (obstacles[pos + 1] != curr_lane) {
                    dp[curr_lane][pos] = dp[curr_lane][pos + 1];
                } else {
                    // Obstacle present, we have to jump side
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++) {
                        if (curr_lane != i && obstacles[pos] != i) {
                            ans = min(ans, 1 + dp[i][pos + 1]);
                        }
                    }
                    dp[curr_lane][pos] = ans;
                }
            }
        }

        // Return the minimum jumps needed starting from lane 2 at position 0
        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }

    int minSideJumps(vector<int>& obstacles) {
        // Uncomment this line if you want to use the recursive method with memoization.
        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        // return solve(obstacles, 2, 0, dp);

        // Using the tabulation method by default.
        return solveTab(obstacles);
    }
};
