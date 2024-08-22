class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        
        // If there are no steps, no cost
        if (N == 0) return 0;
        // If there's only one step, the minimum cost to reach it is the cost of that step
        if (N == 1) return cost[0];
        
        // DP array to store the minimum cost to reach each step
        vector<int> dp(N);
        
        // Base cases
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        // Fill the DP array
        for (int i = 2; i < N; ++i) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        
        // Minimum cost to reach the top can be either from the last step or the second last step
        return min(dp[N - 1], dp[N - 2]);
    }
};
