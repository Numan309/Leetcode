class Solution {
public:
    int f(int n, vector<int>& dp) {
        // Base cases
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        // Check if the value is already computed
        if (dp[n] != -1) return dp[n];

        // Recursive calculation with memoization
        dp[n] = f(n - 1, dp) + f(n - 2, dp) + f(n - 3, dp);
        return dp[n];
    }
    int f(int n)
    {
        vector<int>dp(n+3,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
    
    int tribonacci(int n) {
        // vector<int> dp(n + 1, -1);
        return f(n);
    }
};
