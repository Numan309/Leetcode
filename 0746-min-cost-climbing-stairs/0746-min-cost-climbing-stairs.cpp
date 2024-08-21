class Solution {
public:
    int solve(vector<int>& cost, int N, vector<int>& dp) {
        if (N == 0) return cost[0];
        if (N == 1) return cost[1];
        if (dp[N] != -1) return dp[N];
        dp[N] = cost[N] + min(solve(cost, N - 1, dp), solve(cost, N - 2, dp));
        return dp[N];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        vector<int> dp(N, -1);
        int ans = min(solve(cost, N - 1, dp), solve(cost, N - 2, dp));
        return ans;
    }
};
