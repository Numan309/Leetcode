class Solution {
public:
    void solve(int curr,int n,vector<int>&res)
    {
        if(curr>n) {
            return;
        }
        res.push_back(curr);
        
        for(int append = 0;append<=9;append++)
        {
            int newNum = curr*10+append;
            
            if(newNum>n)
                return;
            
            solve(newNum,n,res);
        }
    }
    vector<int> lexicalOrder(int n) {
       vector<int>res;
        for(int i=1;i<=9;i++)
        {
            solve(i,n,res);
        }
        return res;
    }
};