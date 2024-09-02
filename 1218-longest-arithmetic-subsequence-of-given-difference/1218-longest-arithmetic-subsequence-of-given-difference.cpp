class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int>dp;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
          int temp = arr[i]-difference;
            int res = 0;
            
            if(dp.count(temp))
                res = dp[temp];
            //current element update
            dp[arr[i]] = 1+res;
            ans = max(ans,dp[arr[i]]);
        }
        return ans;
    }
};