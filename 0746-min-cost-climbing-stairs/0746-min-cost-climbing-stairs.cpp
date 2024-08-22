class Solution {
public:
    int dp[1000];
    int solve(vector<int>& cost, int N) {
        if (N == 0) return cost[0];
        if (N == 1) return cost[1];
        if (dp[N] != -1) return dp[N];
        dp[N] = cost[N] + min(solve(cost, N - 1), solve(cost, N - 2));
        return dp[N];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        memset(dp,-1,sizeof(dp));
        int ans = min(solve(cost, N - 1), solve(cost, N - 2));
        return ans;
    }
};
