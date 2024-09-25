class Solution {
public:
    int M = 1e9+7;
    int dp[1001];
    int solve(int n)
    {
       if(n==1 || n==2) return n;
        if(n==3) return 5;
        if(dp[n]!=-1) return dp[n];
        int ans = (2*solve(n-1)%M+solve(n-3)%M)%M;
        return dp[n] = ans;
    }
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
         return solve(n);
    }
};