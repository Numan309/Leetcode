class Solution {
public:
    int solve(vector<int>& slices, int ind, int n, int end, vector<vector<int>>& dp) {
        if (n == 0 || ind > end) {
            return 0;
        }
        if (dp[ind][n] != -1) {
            return dp[ind][n];
        }
        
        int take = slices[ind] + solve(slices, ind + 2, n - 1, end, dp);
        int notTake = solve(slices, ind + 1, n, end, dp);       
        return dp[ind][n] = max(take, notTake);
    }

    int solveTab(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k + 2, vector<int>(k / 3 + 2, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k / 3 + 2, 0));

        // DP table for the first case (excluding the last slice)
        for (int ind = k - 2; ind >= 0; --ind) {
            for (int n = 1; n <= k / 3; ++n) {
                int take = (ind + 2 <= k - 1) ? slices[ind] + dp1[ind + 2][n - 1] : slices[ind];
                int notTake = dp1[ind + 1][n];
                dp1[ind][n] = max(take, notTake);
            }
        }
        int case1 = dp1[0][k / 3];

        // DP table for the second case (excluding the first slice)
        for (int ind = k - 1; ind >= 1; --ind) {
            for (int n = 1; n <= k / 3; ++n) {
                int take = (ind + 2 <= k - 1) ? slices[ind] + dp2[ind + 2][n - 1] : slices[ind];
                int notTake = dp2[ind + 1][n];
                dp2[ind][n] = max(take, notTake);
            }
        }
        int case2 = dp2[1][k / 3];

        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {
        return solveTab(slices);
    }
};
