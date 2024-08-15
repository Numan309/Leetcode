class Solution {
public:
  
    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
        vector<int> dp(n, 1); // Initialize dp array with 1's for LIS length
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        // The length of the longest increasing subsequence will be the maximum value in dp
        return *max_element(dp.begin(), dp.end());
     
    }
};



