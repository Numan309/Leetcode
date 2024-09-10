class Solution {
public:
//   int maxCoinsHelper(int i,int j,vector<int> &nums,vector<vector<int>>&dp) {
//     if (i > j) return 0;
//     int maxCoins = INT_MIN;
    
//       if(dp[i][j]!=-1) return dp[i][j];
//     // Iterate through each possible balloon to burst last
//     for (int k = i; k <= j; k++) {
//         // Calculate the coins obtained by bursting the k-th balloon last
//         int coins = nums[i - 1] * nums[k] * nums[j + 1];
        
//         // Recursively calculate the maximum coins for the remaining balloons
//         int remainingCoins = maxCoinsHelper(i, k - 1, nums,dp) + maxCoinsHelper(k + 1, j, nums,dp);
        
//         // Update the maximum coins
//         maxCoins = max(maxCoins, coins + remainingCoins);
//     }
    
//     return dp[i][j] = maxCoins;
// }
   int maxCoins(vector<int>& nums) {
    int n = nums.size();
    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    // Initialize the DP table
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    
    // Fill the DP table
    for(int i = n; i >= 1; --i) {
        for(int j = 1; j <= n; ++j) {
            if(i > j) continue;
            int maxCoins = INT_MIN;
            for(int k = i; k <= j; ++k) {
                int coins = nums[i - 1] * nums[k] * nums[j + 1];
                int remainingCoins = dp[i][k - 1] + dp[k + 1][j];
                maxCoins = max(maxCoins, coins + remainingCoins);
            }
            dp[i][j] = maxCoins;
        }
    }
    
    return dp[1][n];
}
};