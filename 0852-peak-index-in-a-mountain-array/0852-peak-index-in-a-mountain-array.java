class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int n = arr.length;

    // Check the first and last elements separately
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            return i; // Return the index of the peak
        }
    }

    // If no peak found, return -1 (though this shouldn't happen in a valid mountain array)
    return -1;
    }
}