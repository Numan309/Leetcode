class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
          List<Integer> indices = new ArrayList<>();
        int n = nums.length;

        // Create a copy of nums and sort it
    //    int[] sortedNums = Arrays.copyOf(nums, n);
        Arrays.sort(nums);

        // Iterate through the sorted array to find target indices
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                indices.add(i);
            }
        }

        return indices;
    }
}