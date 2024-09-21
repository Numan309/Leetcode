class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {    
        int n = obstacles.size();
       vector<int>ans;
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
             int index = upper_bound(ans.begin(), ans.end(), obstacles[i]) - ans.begin();
            if(index==ans.size())
            {
                ans.push_back(obstacles[i]);
            }else{
                ans[index] = obstacles[i];
            }
            res[i] = index+1; 
        }
        return res;
    }
};