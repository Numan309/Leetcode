class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // for ex:  s1:brute. s2:groot
        //  bue , goo ,lcs in both string is 'rt'
        // so our formula comes. s1+s2-len(lcs)
        
      int n = str1.size();
    int m = str2.size();
    
    // Step 1: Calculate the length of LCS using dynamic programming
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (str1[i] == str2[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    // Step 2: Construct the SCS using the LCS table
    string scs;
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        if (str1[i] == str2[j]) {
            scs += str1[i];
            i++;
            j++;
        } else if (dp[i + 1][j] >= dp[i][j + 1]) {
            scs += str1[i];
            i++;
        } else {
            scs += str2[j];
            j++;
        }
    }
    
    // Add remaining characters of str1 and str2
    while (i < n) scs += str1[i++];
    while (j < m) scs += str2[j++];
    
    return scs;
    }
};