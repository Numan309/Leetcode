class Solution {
public:
    int solve(vector<int> &obstacles,int curr_lane,int pos,vector<vector<int>>&dp)
    {
        int n = obstacles.size()-1;
        // Base case
        if(pos==n){
            return 0;
        } 
        if(dp[curr_lane][pos]!=-1) return dp[curr_lane][pos];
        if(obstacles[pos+1]!=curr_lane)
        {
            return solve(obstacles,curr_lane,pos+1,dp);
        }else{
            //Obstacles present we have to jump side 
            int ans = INT_MAX;
            for(int i=1;i<=3;i++)
            {
                if(curr_lane!=i && obstacles[pos]!=i)
                    ans = min(ans,1+solve(obstacles,i,pos,dp));
              dp[curr_lane][pos] = ans;
            }
              return  dp[curr_lane][pos];
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
        return solve(obstacles,2,0,dp);
    }
};