class Solution {
    public int[] sortArray(int[] nums) {
      if (nums == null || nums.length <= 1) {
            return nums;
        }
        
        // Use Arrays.sort() to sort the array
        Arrays.sort(nums);
        
        return nums;
            
    }
}