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
  //Tabulation
      int solveTab(vector<int>&prices)
    {
          int n = prices.size();
           vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                for(int limit = 1;limit<=2;limit++)
                {
                  int profit = 0;
        if(buy)
        {
            int buyKaro = -prices[ind]+dp[ind+1][0][limit];
            int skipKaro = 0+dp[ind+1][1][limit];
            profit = max(buyKaro,skipKaro);
        }else{
            int sellKaro = +prices[ind]+dp[ind+1][1][limit-1];
            int skipKaro = 0+dp[ind+1][0][limit];
            profit = max(sellKaro,skipKaro);
        }
         dp[ind][buy][limit] = profit;
            }
        }
        }    
        return dp[0][1][2];
    }
    //Space Optimize
      int solveOpt(vector<int>&prices)
    {
          int n = prices.size();
           // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
          vector<vector<int>>curr(2,vector<int>(3,0));
          vector<vector<int>>next(2,vector<int>(3,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                for(int limit = 1;limit<=2;limit++)
                {
                  int profit = 0;
        if(buy)
        {
            int buyKaro = -prices[ind]+next[0][limit];
            int skipKaro = 0+next[1][limit];
            profit = max(buyKaro,skipKaro);
        }else{
            int sellKaro = +prices[ind]+next[1][limit-1];
            int skipKaro = 0+next[0][limit];
            profit = max(sellKaro,skipKaro);
        }
        curr[buy][limit] = profit;
            }
               
        }
             next = curr;
        }    
        return next[1][2];
    }
    
          
    int maxProfit(vector<int>& prices) {
     //   int n = prices.size();
      // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
      //   return solveMemo(0,1,prices,2,dp);
        
        return solveOpt(prices);
    }
};