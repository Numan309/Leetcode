class Solution {
    public void rotate(int[] nums, int k) {
         int n = nums.length;
        k = k % n; // to handle cases where k > n
        
        // Create a temporary array to store rotated elements
        int[] temp = new int[n];
        
        // Copy elements from nums to temp with rotation
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }
        
        // Copy elements from temp back to nums
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
}
    
