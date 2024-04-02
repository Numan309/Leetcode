class Solution {
    public int longestOnes(int[] nums, int k) {
        int l = 0;
        int r = 0;
        int maxL = 0;
        int zeroes = 0;
        
        while (r < nums.length) {
            if (nums[r] == 0)
                zeroes++;
            
            while (zeroes > k) {
                if (nums[l] == 0)
                    zeroes--;
                l++;
            }
            
            int len = r - l + 1; // Calculate the length of the current subarray
            
            maxL = Math.max(maxL, len);
            
            r++;
        }
        
        return maxL;
    }
}
