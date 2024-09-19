class Solution {
public:
    int dp[1001][1001];
    // Comparator to sort pairs
    static bool comp(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    // Recursive function to find the longest chain
    int solve(vector<vector<int>>& pairs, int curr, int prev) {
        int n = pairs.size();
        if (curr == n) return 0; // Base case: no more pairs to process
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        int take = 0, notTake = 0;

        // Check if we can take the current pair
        if (prev == -1 || pairs[curr][0] > pairs[prev][1]) {
            take = 1 + solve(pairs, curr + 1, curr); 
        }
        
        notTake = solve(pairs, curr + 1, prev); 
         int ans = max(take, notTake); 
        return dp[curr][prev+1] = ans;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), comp); // Correct sorting order
        return solve(pairs, 0, -1); 
    }
};
