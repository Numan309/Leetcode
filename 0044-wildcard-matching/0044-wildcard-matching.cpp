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
    //Tabulation
    int solveTab(string &str,string &pattern)
    {
      vector<vector<int>>dp(str.size()+1,vector<int>(pattern.size()+1,0));
        dp[0][0] = true;
        for(int j=1;j<=pattern.size();j++)
        {
            bool flag = true;
             for(int k=1;k<=j;k++)
            {
                if(pattern[k-1]!='*')
                {
                   flag = false;
                    break;
                }
            }
             dp[0][j] = flag;
        }
        for(int i=1;i<=str.size();i++)
        {
            for(int j=1;j<=pattern.size();j++)
            {
               if(str[i-1]==pattern[j-1] || pattern[j-1]=='?')
        
            dp[i][j] = dp[i-1][j-1];
        else if(pattern[j-1]=='*')
        
     dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
        else
            dp[i][j] = false;
            }
        }
        return dp[str.size()][pattern.size()];
    }
        
    bool isMatch(string s, string p) {
       //  int n = s.size();
       //  int m = p.size();
       // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solveTab(s,p);
    }
};