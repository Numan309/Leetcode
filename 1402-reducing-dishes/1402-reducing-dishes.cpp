class Solution {
public:
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
    int maxSatisfaction(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,0,0,dp);
    }
};