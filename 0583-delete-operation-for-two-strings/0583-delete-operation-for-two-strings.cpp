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
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(text1,text2,0,0,dp);
    }
    int minDistance(string word1, string word2) {
         int lcsLength = longestCommonSubsequence(word1, word2);
        return word1.length() - lcsLength + word2.length() - lcsLength;
    }
};