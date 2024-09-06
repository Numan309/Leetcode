#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<int>& prices, int ind, int buy, int k, vector<vector<vector<int>>>& dp) {
        if (ind >= prices.size() || k == 0) return 0; // Base case
        if (dp[ind][buy][k] != -1) return dp[ind][buy][k]; // Return the cached result

        int profit;
        if (buy) {
            // Option to buy stock
            int buyKaro = -prices[ind] + solve(prices, ind + 1, 0, k, dp);
            // Option to skip buying
            int skipKaro = solve(prices, ind + 1, 1, k, dp);
            profit = max(buyKaro, skipKaro);
        } else {
            // Option to sell stock
            int sellKaro = prices[ind] + solve(prices, ind + 1, 1, k - 1, dp);
            // Option to skip selling
            int skipKaro = solve(prices, ind + 1, 0, k, dp);
            profit = max(sellKaro, skipKaro);
        }

        return dp[ind][buy][k] = profit; // Cache the result
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(prices, 0, 1, k, dp);
    }
};
