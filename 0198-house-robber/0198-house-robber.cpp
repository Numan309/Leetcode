class Solution {
public:
    
    int dp[100];
    int solve(vector<int>&nums,int n)
    {
        if(n<0) return 0;
        if(n==0) return nums[0];
        if(dp[n]!=-1) return dp[n];
        int include = solve(nums,n-2)+nums[n];
        int exclude = solve(nums,n-1)+0;
        int res = max(include,exclude);
        return dp[n]=res;
    }
    int rob(vector<int>& nums){
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,n-1);
        return ans;
    }
};