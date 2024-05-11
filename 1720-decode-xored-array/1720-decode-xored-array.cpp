class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        //a^b=c ,b^c=a
        vector<int>ans;
        ans.push_back(first);
        for(auto i:encoded){
            ans.push_back(ans.back()^i);
        }
        return ans;
    }
};