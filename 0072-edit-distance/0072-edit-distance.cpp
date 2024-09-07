class Solution {
public:
    int solve(string &a,string &b,int i,int j,vector<vector<int>>&dp)
    {
        if(i==a.length()) return b.length()-j;
        if(j==b.length()) return a.length()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(a[i]==b[j])
        {
            return solve(a,b,i+1,j+1,dp);
        }else{
            //Insert
            int InsertAns = 1+solve(a,b,i,j+1,dp);
            //Delete
            int DeleteAns = 1+solve(a,b,i+1,j,dp);
            //Replace
            int ReplaceAns = 1+solve(a,b,i+1,j+1,dp);
            ans = min({InsertAns,DeleteAns,ReplaceAns});
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(word1,word2,0,0,dp);
    }
};