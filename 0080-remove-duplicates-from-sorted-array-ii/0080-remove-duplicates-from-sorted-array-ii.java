class Solution {
    public int removeDuplicates(int[] nums) {
        int n=nums.length;
        int ans=2;
        for(int i=2;i<n;i++)
        {
            if(nums[i]!=nums[ans-2])
            {
                nums[ans]=nums[i];
                ans++;
            }
        } 
        return ans;   
    }
}