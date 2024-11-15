#define vi vector<int>
#define vvi vector<vector<int>>
class Solution {
public:
    void solve(vi &candidates,int target,vi &curr,int idx,vvi &res)
    {
        if(target<0)
            return;
        
        if(target==0){
            res.push_back(curr);
        return;
        }
        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            curr.push_back(candidates[i]); //DO
            solve(candidates,target-candidates[i],curr,i+1,res);
            curr.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vvi res;
        vi curr;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,curr,0,res);
        return res;
    }
};