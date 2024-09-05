class Solution {
public:
     int solve(int ind,int buy,vector<int>&prices,int limit)
     {
        if(ind==prices.size()) return 0;
        if(limit==0) return 0; 
        int profit = 0;
        if(buy)
        {
            int buyKaro = -prices[ind]+solve(ind+1,0,prices,limit);
            int skipKaro = 0+solve(ind+1,1,prices,limit);
            profit = max(buyKaro,skipKaro);
        }else{
            int sellKaro = +prices[ind]+solve(ind+1,1,prices,limit-1);
            int skipKaro = 0+solve(ind+1,0,prices,limit);
            profit = max(sellKaro,skipKaro);
        }
        return profit;
    }
    //Memoisation
     int solveMemo(int ind,int buy,vector<int>&prices,int limit,
                  vector<vector<vector<int>>>&dp)
     {
        if(ind==prices.size()) return 0;
        if(limit==0) return 0; 
        if(dp[ind][buy][limit]!=-1) return dp[ind][buy][limit]; 
        int profit = 0;
        if(buy)
        {
            int buyKaro = -prices[ind]+solveMemo(ind+1,0,prices,limit,dp);
            int skipKaro = 0+solveMemo(ind+1,1,prices,limit,dp);
            profit = max(buyKaro,skipKaro);
        }else{
            int sellKaro = +prices[ind]+solveMemo(ind+1,1,prices,limit-1,dp);
            int skipKaro = 0+solveMemo(ind+1,0,prices,limit,dp);
            profit = max(sellKaro,skipKaro);
        }
        return dp[ind][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
      vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solveMemo(0,1,prices,2,dp);
    }
};