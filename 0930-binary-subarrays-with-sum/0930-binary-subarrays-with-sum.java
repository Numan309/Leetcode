class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
       return helper(nums, goal)-helper(nums, goal-1);
    }
    public static int helper(int[] nums, int k){
         int count = 0;
        int l = 0;
        int r = 0;
        int ans =0;
        while(r<nums.length){
            if(nums[r]==1) count++;
            while(l<=r && count>k){
                if(nums[l]==1) count--;
                l++;
            }
            ans+=(r-l+1);
            r++;
        }

        return ans;
    }
}