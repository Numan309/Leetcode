class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int start=0,end=0,n = nums.size();
        int cnt = 0;
        while(end<n)
        {
           product*=nums[end];
        
        while(product>=k && start<=end)
        {
            product/=nums[start];
            start++;
        }
            cnt+= 1+(end-start);
            end++;
        }
        return cnt;
        
    }
};