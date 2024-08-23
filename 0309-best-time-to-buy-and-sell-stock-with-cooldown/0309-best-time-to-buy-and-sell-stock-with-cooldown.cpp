class Solution {
public:
    int dp[5000][1000];
    
    int solve(int ind, int buy, vector<int> &prices, int n) {
        if (ind >= n) return 0; // Base case: no more days to trade

        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy == 1) {
            // Option to buy
            dp[ind][buy] = max(-prices[ind] + solve(ind + 1, 0, prices, n), 
                               0 + solve(ind + 1, 1, prices, n));
        } else {
            // Option to sell
            dp[ind][buy] = max(prices[ind] + solve(ind + 2, 1, prices, n), 
                               0 + solve(ind + 1, 0, prices, n));
        }

        return dp[ind][buy];
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp)); // Initialize the dp array with -1
        int n = prices.size();
        return solve(0, 1, prices, n); // Start with buying option on the first day
    }
};
