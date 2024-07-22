class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0,end = 0,mid,ans;
        for(int i=0;i<n;i++)
        {
           start = max(start,nums[i]);
            end+=nums[i];
        }
        while(start<=end)
        {
            mid = start+(end-start)/2;
            int res = 0,cnt = 1;
            for(int i=0;i<n;i++)
            {
                res+=nums[i];
                if(res>mid)
                {
                    cnt++;
                    res = nums[i];
                }
            }
            if(cnt<=k)
            {
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};