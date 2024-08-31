class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int ind, bool swapped,vector<vector<int>>&dp) {
        // Base case: If we have processed all elements
        if (ind == nums1.size()) return 0;
        if(dp[ind][swapped]!=-1) return dp[ind][swapped];
        // Values for the current index
        int prev1 = (ind == 0) ? INT_MIN : nums1[ind - 1];
        int prev2 = (ind == 0) ? INT_MIN : nums2[ind - 1];
        
        if (swapped) {
            swap(prev1, prev2);
        }

        int ans = INT_MAX;
        
        // No swap case
        if (nums1[ind] > prev1 && nums2[ind] > prev2) {
            ans = solve(nums1, nums2, ind + 1, 0,dp);
        }

        // Swap case
        if (nums1[ind] > prev2 && nums2[ind] > prev1) {
            ans = min(ans, 1 + solve(nums1, nums2, ind + 1, 1,dp));
        }
        
        return dp[ind][swapped] = ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // return solve(nums1, nums2, 0, 0);
        int n = nums1.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(nums1, nums2, 0, 0,dp);
    }
};