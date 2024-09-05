class Solution {
public:
    int solve(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit = 0;
        if(buy)
        {
            int buyKaro = -prices[ind]+solve(ind+1,0,prices,dp);
            int skipKaro = 0+solve(ind+1,1,prices,dp);
            profit = max(buyKaro,skipKaro);
        }else{
            int sellKaro = +prices[ind]+solve(ind+1,1,prices,dp);
            int skipKaro = 0+solve(ind+1,0,prices,dp);
            profit = max(sellKaro,skipKaro);
        }
        return dp[ind][buy] = profit;
    }
    int solveTab(vector<int>&prices)
    {
          int n = prices.size();
          vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                  int profit = 0;
        if(buy)
        {
            int buyKaro = -prices[ind]+dp[ind+1][0];
            int skipKaro = 0+dp[ind+1][1];
            profit = max(buyKaro,skipKaro);
        }else{
            int sellKaro = +prices[ind]+dp[ind+1][1];
            int skipKaro = 0+dp[ind+1][0];
            profit = max(sellKaro,skipKaro);
        }
         dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solve(0,1,prices,dp);
        
        return solveTab(prices);
    }
};