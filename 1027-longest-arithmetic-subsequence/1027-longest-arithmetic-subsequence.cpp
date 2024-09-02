class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;

        int ans = 0;
        unordered_map<int, int> dp;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                int cnt = 1;

                if (dp.count(j * 1000 + diff))
                    cnt = dp[j * 1000 + diff];

                dp[i * 1000 + diff] = 1 + cnt;
                ans = std::max(ans, dp[i * 1000 + diff]);
            }
        }

        return ans;
    }
};