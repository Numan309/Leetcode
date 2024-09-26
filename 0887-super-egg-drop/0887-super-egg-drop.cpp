class Solution {
public:
    int solve(int k, int n, vector<std::vector<int>>& dp) {
        // Base cases
        if (n == 0) return 0; // No floors, no trials needed
        if (k == 1) return n; // Only one egg, we need to try all floors
        if (dp[k][n] != -1) return dp[k][n];

        int minTrials = INT_MAX;

        // Use binary search for optimization
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If the egg breaks
            int breakEgg = solve(k - 1, mid - 1, dp);
            // If the egg doesn't break
            int notBreakEgg = solve(k, n - mid, dp);
            
            // Worst case trials needed
            int worstCase = 1 + max(breakEgg, notBreakEgg);

            // Update the minimum trials needed
            minTrials = min(minTrials, worstCase);

            // Binary search adjustment
            if (breakEgg > notBreakEgg) {
                high = mid - 1; // If egg breaks, go lower
            } else {
                low = mid + 1; // If egg doesn't break, go higher
            }
        }

        return dp[k][n] = minTrials;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1,vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};