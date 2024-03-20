class Solution {
    public int[] singleNumber(int[] nums) {
        int xorr = 0;
        int n = nums.length;
        for(int i = 0; i < n; i++){
            xorr ^= nums[i];
        }
        
        int rightmost = xorr & -xorr;
        int b1 = 0;
        int b2 = 0;
        
        for(int i = 0; i < n; i++) {
            if((nums[i] & rightmost) == 0) {
                b1 ^= nums[i];
            } else {
                b2 ^= nums[i];
            }
        }
        
        return new int[]{b1, b2};
    }
}
