class Solution {
    public int minimumDifference(int[] nums, int k) {
    int min = Integer.MAX_VALUE;
    int start = 0;
    int end = k-1;
    if(k==1){
        return 0;
    }
     Arrays.sort(nums); 
     while(end<nums.length){
         min = Math.min(min,nums[end]-nums[start]);
         start++;
         end++;
     }
     return min;
    }
}