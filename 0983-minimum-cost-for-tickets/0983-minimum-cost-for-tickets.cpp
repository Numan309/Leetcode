class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int ind, int n, vector<int>& dp) {
        // Base case
        if (ind >= n) return 0;

        // Memoization check
        if (dp[ind] != -1) return dp[ind];

        // 1 Day Pass
        int option1 = costs[0] + solve(days, costs, ind + 1, n, dp);

        // 7 Day Pass
        int i;
        for (i = ind; i < n && days[i] < days[ind] + 7; i++);
        int option2 = costs[1] + solve(days, costs, i, n, dp);

        // 30 Day Pass
        for (i = ind; i < n && days[i] < days[ind] + 30; i++);
        int option3 = costs[2] + solve(days, costs, i, n, dp);

        // Store the result in dp[ind] and return it
        dp[ind] = min(option1, min(option2, option3));
        return dp[ind];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1); // Initialize dp vector with -1
        return solve(days, costs, 0, n, dp);
    }
};
