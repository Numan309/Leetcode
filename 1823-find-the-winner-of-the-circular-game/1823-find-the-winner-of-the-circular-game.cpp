class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            v.push_back(i);
        }
        int i = 0;
        while(v.size()>1)
        {
            int idx = (i+k-1)%v.size();
            v.erase(v.begin()+idx);
            i = idx;
        }
        return v[0];
    }
};