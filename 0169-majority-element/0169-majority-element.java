class Solution {
    public int majorityElement(int[] nums) {
        //Brute force Approach
        //TC. o(n^2)
        int n = nums.length;
        for(int i = 0;i<n;i++){
          int  cnt = 0;
            for(int j= 0;j<n;j++){
                if(nums[j]==nums[i]){
                    cnt ++;
                }

            }
            if(cnt>n/2) return nums[i];
        }
        return -1;
    }
}