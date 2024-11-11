#define vi vector<int>
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
       int cnt = 0;
        int i = 1;
        vi L = intervals[0];
        
        while(i<n)
        {
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            
            int last_end = L[1];
            
            if(curr_start>=last_end)
            {
                L=intervals[i];
               
            }else if(curr_end>=last_end)
            {
             
                cnt++;
            }else if(curr_end<last_end)
            {
                L = intervals[i];
              
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};