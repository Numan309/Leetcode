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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};