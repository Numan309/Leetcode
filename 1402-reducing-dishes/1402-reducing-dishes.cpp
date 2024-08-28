class Solution {
public:
    //Memoisation
    int solve(vector<int>& satisfaction,int ind,int time, vector<vector<int>>&dp)
    {
        if(ind==satisfaction.size()) return 0;
        if(dp[ind][time]!=-1) return dp[ind][time];
        int include = satisfaction[ind]*(time+1)+solve(satisfaction,
                ind+1,time+1,dp);
        int exclude = 0+solve(satisfaction,ind+1,time,dp);
          int ans = max(include,exclude);
        return dp[ind][time]=ans;
    }
    //Tabulation 
      int solveTab(vector<int>& satisfaction)
    {
        int n = satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind = n-1;ind>=0;ind--)
        {
            for(int time = ind;time>=0;time--)
            {   
        int include = satisfaction[ind]*(time+1)+dp[ind+1][time+1];
        int exclude = 0+dp[ind+1][time];
           dp[ind][time] = max(include,exclude);
            }
        }
          return dp[0][0];
    }
    //Space optimized
      int solveTab2(vector<int>& satisfaction)
    {
        int n = satisfaction.size();
        vector<int>curr(n+1,0);
         vector<int>next(n+1,0); 
        for(int ind = n-1;ind>=0;ind--)
        {
            for(int time = ind;time>=0;time--)
            {   
        int include = satisfaction[ind]*(time+1)+next[time+1];
        int exclude = 0+next[time];
          curr[time] = max(include,exclude);
            }
            next = curr;
        }
          return next[0];
    }
    
    int maxSatisfaction(vector<int>& satisfaction){
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        // return solve(satisfaction,0,0,dp);
        return solveTab2(satisfaction);
    }
};