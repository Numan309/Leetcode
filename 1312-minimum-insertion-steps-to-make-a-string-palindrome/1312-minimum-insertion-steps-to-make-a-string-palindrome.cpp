class Solution {
public:
     int solve(string a,string b)
    {
         int n = a.size();
        int m = b.size();
        
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);
        
        // Start from the end of the strings
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int ans = 0;
                if (a[i] == b[j]) {
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
    
    int longestPalindromeSubseq(string s) {
        string rev = s;
       reverse(rev.begin(),rev.end());
       int ans = solve(s,rev);
       return ans;
    }
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};