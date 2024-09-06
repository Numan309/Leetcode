class Solution {
public:
    int solve(string& a,string& b,int i,int j,vector<vector<int>>&dp)
    {
        if (i >= a.length() || j >= b.length()) {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(a[i]==b[j])
        {
            ans = 1+solve(a,b,i+1,j+1,dp);
        }else{
              ans = max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
        }
        return dp[i][j] = ans;
    }
    int solveTab(string text1,string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0)); 
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
           int ans = 0;
        if(text1[i]==text2[j])
        {
            ans = 1+dp[i+1][j+1];
        }else{
              ans = max(dp[i+1][j],dp[i][j+1]);
        }
           dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
   int solveOpt(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);
        
        // Start from the end of the strings
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int ans = 0;
                if (text1[i] == text2[j]) {
                    ans = 1 + next[j + 1];
                } else {
                    ans = max(next[j], curr[j + 1]);
                }
                curr[j] = ans;
            }
            // Copy current to next
            swap(curr, next);
        }
        
        return next[0];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.size();
        // int m = text2.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve(text1,text2,0,0,dp);
        
        return solveOpt(text1,text2);
    }
};