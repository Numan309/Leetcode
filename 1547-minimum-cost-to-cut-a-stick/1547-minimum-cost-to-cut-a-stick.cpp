class Solution {
public:
    int solve(int i, int j, vector<int>& cuts,vector<vector<int>>&dp) {
        if (i > j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for (int ind = i; ind <= j; ind++) {
            // Calculate the cost for the current cut
            int res = cuts[j + 1] - cuts[i - 1] 
                    + solve(i, ind - 1, cuts,dp) 
                    + solve(ind + 1, j, cuts,dp);
            ans = min(ans, res);
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);  // Add the starting point
        cuts.push_back(n);  // Add the ending point
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(c+2,vector<int>(c+2,-1));
        return solve(1, c, cuts,dp);  // Start from the first cut to the last cut
    }
};
