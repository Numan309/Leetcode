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
        int n = slices.size();
        int k = n;
        vector<vector<int>> dp1(k + 2, vector<int>(k / 3 + 2, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k / 3 + 2, 0));

        for (int ind = k - 2; ind >= 0; ind--) {
            for (int count = 1; count <= k / 3; count++) {
                int take = slices[ind] + dp1[ind + 2][count - 1];
                int notTake = dp1[ind + 1][count];
                dp1[ind][count] = max(take, notTake);
            }
        }
        int case1 = dp1[0][k / 3];

        for (int ind = k - 1; ind >= 1; ind--) {
            for (int count = 1; count <= k / 3; count++) {
                int take = slices[ind] + dp2[ind + 2][count - 1];
                int notTake = dp2[ind + 1][count];
                dp2[ind][count] = max(take, notTake);
            }
        }
        int case2 = dp2[1][k / 3];
        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {
        return solveTab(slices);
    }
};
