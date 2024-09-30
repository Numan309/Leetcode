class Solution {
public:
    int Z,O;
    int L,H;
    const int M = 1e9+7;
    int dp[100001];
    int solve(int l)
    {
        if(l>H) return 0;
        bool addOne = false;
        if(l>=L){
            addOne = true;
        }
        if(dp[l]!=-1) return dp[l];
        int append_zero = solve(l+Z);
        int append_one = solve(l+O);
        return dp[l] = (addOne+append_zero+append_one)%M;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        L = low;
        H = high;
        Z = zero;
        O = one;
        
        memset(dp,-1,sizeof(dp));
        return solve(0);
    }
};