class Solution {
public:
     int solve(string &pattern,string &str,int i,int j,
              vector<vector<int>>&dp)
    {
        if(i==0 && j==0) return 1;
        if(i>0 && j==0) return 0;
        if(i==0 && j>0)
        {
            for(int k=1;k<=j;k++)
            {
                if(pattern[k-1]!='*')
                {
                    return 0;
                }
            }
            return 1;
        }
         if(dp[i][j]!=-1) return dp[i][j];
        //Match
        if(str[i-1]==pattern[j-1] || pattern[j-1]=='?')
        
            return dp[i][j] = solve(pattern,str,i-1,j-1,dp);
        else if(pattern[j-1]=='*')
        
      return dp[i][j] = (solve(pattern,str,i-1,j,dp) || solve(pattern,str,i,j-1,dp));
        else
            return false;
        }
        
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(p,s,n,m,dp);
    }
};