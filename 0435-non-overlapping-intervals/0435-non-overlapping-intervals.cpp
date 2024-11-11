#define vi vector<int>
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int cnt = 0;
        int i=0,j = 1;
        
        while(j<n)
        {
            vi curr = intervals[i];
            vi next = intervals[j];
            
            int cs = curr[0];
            int ce = curr[1];
            
            int ns = next[0];
            int ne = next[1];
            
            if(ce<=ns) // no overlapping
            {
                i = j;
                j++;
            }else if(ce<=ne)//overlapping
            {
                j++;
                cnt++;
            }else if(ce>ne) // overlapping
            {
                i=j;
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};