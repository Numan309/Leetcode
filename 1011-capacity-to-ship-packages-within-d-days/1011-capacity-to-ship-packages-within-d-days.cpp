class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int n = weights.size();
        int start = 0,end = 0,mid,ans;
        for(int i=0;i<n;i++)
        {
          start = max(start,weights[i]);
            end+=weights[i];
            
        }
        while(start<=end)
        {
            mid = start+(end-start)/2;
            int capacity = 0,cnt = 1;
            for(int i=0;i<n;i++)
            {
                capacity+=weights[i];
                if(capacity>mid)
                {
                    cnt++;
                    capacity = weights[i];
                }
            }
            if(cnt<=days){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};