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

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k, vector<int>(k / 3 + 1, -1));
        vector<vector<int>> dp2(k, vector<int>(k / 3 + 1, -1));
        
        int case1 = solve(slices, 0, k / 3, k - 2, dp1);
        int case2 = solve(slices, 1, k / 3, k - 1, dp2);
        
        return max(case1, case2);
    }
};
