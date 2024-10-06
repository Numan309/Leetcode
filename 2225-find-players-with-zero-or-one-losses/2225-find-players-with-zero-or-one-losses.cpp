class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            int loser = matches[i][1];
            m[loser]++;
        }
        vector<int>neverLost;
        vector<int>oneLost;
        
        for(int i=0;i<n;i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];
            
            if(m.find(winner)==m.end())
            {
                neverLost.push_back(winner);
                m[winner] = 2;
            }
            if(m[loser]==1)
            {
                oneLost.push_back(loser);
            }
        }
            sort(neverLost.begin(),neverLost.end());
            sort(oneLost.begin(),oneLost.end());
        
        return {neverLost,oneLost};
    }
};