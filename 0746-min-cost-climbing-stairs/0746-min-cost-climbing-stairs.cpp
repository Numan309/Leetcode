class Solution {
public:
    int solve(vector<int>& cost, int i, vector<int>& dp) {
        if (i >= cost.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int takeOneStep = cost[i] + solve(cost, i + 1, dp);
        int takeTwoSteps = (i + 1 < cost.size() ? cost[i + 1] : 0) + solve(cost, i + 2, dp);
        return dp[i] = min(takeOneStep, takeTwoSteps);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return solve(cost, 0, dp);
    }
};
