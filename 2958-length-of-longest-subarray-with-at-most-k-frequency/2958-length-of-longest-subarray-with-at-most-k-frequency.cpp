class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        int start = 0,end = 0,len = 0,n = nums.size();
        while(end<n)
        {
            cnt[nums[end]]++;
            
            while(cnt[nums[end]]>k)
            {
                cnt[nums[start]]--;
                start++;    
                
            }
             len=max(len,end-start+1);
                 end++;
           
        }
        return len;
    }
};