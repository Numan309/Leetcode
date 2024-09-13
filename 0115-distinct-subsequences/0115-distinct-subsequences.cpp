class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;  // A large prime number for modulo
        int m = s.size();
        int n = t.size();
        
        // Use long long for the dp table to handle larger values
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        
        // An empty t is a subsequence of any prefix of s
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                } else {
                    dp[i][j] = dp[i - 1][j] % MOD;
                }
            }
        }

        return dp[m][n];
    }
};