class Solution {
public:
    //Tabulation
    int solve(vector<int>& days, vector<int>& costs,int n) {
      vector<int>dp(n+1,INT_MAX);
        dp[n] = 0;
        for(int j = n-1;j>=0;j--)
        {  //1 day pass
            int op1 = costs[0]+dp[j+1];
            // 7 day pass
            int i;
            for(i=j;i<n && days[i]<days[j]+7;i++);
              int op2 = costs[1]+dp[i];
            // 30 day pass
            for(i=j;i<n && days[i]<days[j]+30;i++);
              int op3 = costs[2]+dp[i]; 
             dp[j] = min({op1, op2, op3});
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solve(days, costs,n);
    }
};
