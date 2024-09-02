
class Solution {
public:
    // Recursive function to compute the maximum money that can be robbed
    int solve(vector<int>& nums, int start, int end, vector<int>& memo) {
        if (start > end) return 0;
        if (start == end) return nums[start];

        if (memo[start] != -1) return memo[start];
        int include = nums[start] + solve(nums, start + 2, end, memo);
        
        int exclude = solve(nums, start + 1, end, memo);

        memo[start] = max(include, exclude);
        return memo[start];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Only one house to rob
        if (n == 0) return 0; // No houses to rob

        // Initialize memoization vectors for the two cases
        vector<int> memo1(n, -1); // For segment [0, n-2]
        vector<int> memo2(n, -1); // For segment [1, n-1]

        // Compute the maximum amount for both cases
        int maxRob1 = solve(nums, 0, n - 2, memo1);
        int maxRob2 = solve(nums, 1, n - 1, memo2);

        return max(maxRob1, maxRob2);
    }
};
