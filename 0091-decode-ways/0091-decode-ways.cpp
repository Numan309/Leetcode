class Solution {
public:
    int dp[100];

    int numDecodingsRecursive(string s, int n, int index) {
        if (index == n) {
            return 1; // If we reach the end of the string, one way to decode it.
        }

        if (s[index] == '0') {
            return 0; // If the current digit is '0', it cannot be decoded individually.
        }

        if (dp[index] != -1) return dp[index];

        int ways = numDecodingsRecursive(s, n, index + 1); // Decode current digit individually

        if (index + 1 < n && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))) {
            ways += numDecodingsRecursive(s, n, index + 2); // Decode current and next digit together
        }

        return dp[index] = ways;
    }

    int numDecodings(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return numDecodingsRecursive(s, n, 0);
    }
};
