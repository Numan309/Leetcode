class Solution {
public:
    int solve(int n,int k)
    {
        if(n==1) return 0;
        int idx = solve(n-1,k);
        idx = (idx+k)%n;
        return idx;
    }
    int findTheWinner(int n, int k) {
        int res = solve(n,k);
        return res+1;
    }
};