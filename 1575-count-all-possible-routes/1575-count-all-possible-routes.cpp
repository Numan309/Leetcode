class Solution {
public:
    int n;
    const int M = 1e9+7;
    int dp[101][201];
    int solve(vector<int>& locations, int start, int finish, int fuel) {
        
        if (fuel < 0) { 
            return 0;
        }
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        int ans = 0;
        if (start == finish) {
            ans += 1;
        }

        // Explore all other locations
        for (int j = 0; j < n; j++) {
            if (start != j) {
          int remaining_fuel = (fuel - abs(locations[start] - locations[j]))%M;
            ans= (ans+solve(locations, j, finish, remaining_fuel))%M;
            }
        }

        return dp[start][fuel] = ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        memset(dp,-1,sizeof(dp));
        return solve(locations, start, finish, fuel);
    }
};
