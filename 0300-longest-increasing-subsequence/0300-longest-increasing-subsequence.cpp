class Solution {
public:
      int solve(vector<int>&nums,int curr,int prev,vector<vector<int>> &dp)
    {
        //Memoisation method
        //Base case
          int n = nums.size();
        if(curr==n) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
       //Include
       int take = 0;
       if(prev==-1 || nums[curr]>nums[prev])
       take = 1+solve(nums,curr+1,curr,dp);
       //exclude
       int NotTake = 0+solve(nums,curr+1,prev,dp);
       int ans = max(take,NotTake);
       return dp[curr][prev+1] = ans;
    }
    //Tabulation
    
    int solveTab(vector<int>&nums)
    {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--)
    {
        for(int prev = curr-1;prev>=-1;prev--)
        {
       int take = 0;
       if(prev==-1 || nums[curr]>nums[prev])
       take = 1+dp[curr+1][curr+1];
       //exclude
       int NotTake = 0+dp[curr+1][prev+1];
      dp[curr][prev+1] = max(take,NotTake);
     
        }
    }
     return dp[0][0];
    }
    //Optimize approach
    
    int solveOpt(vector<int>&nums)
    {
        int n = nums.size();
        vector<int>currRow(n+1,0);
        vector<int>next(n+1,0);
        
     for(int curr=n-1;curr>=0;curr--)
    {
        for(int prev = curr-1;prev>=-1;prev--)
        {
       int take = 0;
       if(prev==-1 || nums[curr]>nums[prev])
       take = 1+next[curr+1];
       //exclude
       int NotTake = 0+next[prev+1];
      currRow[prev+1] = max(take,NotTake);
     
        }
         next = currRow;
    }
     return next[0];
    }
    int lengthOfLIS(vector<int>& nums) {
       //  int n = nums.size();
       // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(nums,0,-1,dp);
        return solveOpt(nums);
    }
};