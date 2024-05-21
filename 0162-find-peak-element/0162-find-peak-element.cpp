class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int n = nums.size(); // Size of array.

        for (int i = 0; i < n; i++) {
            // Checking for the peak:
            if ((i == 0 || nums[i - 1] < nums[i])
                && (i == n - 1 || nums[i] > nums[i + 1])) {
                return i;
            }
        }
        // Dummy return statement
        return -1;
    }

    int peakElement(int nums[], int n) {
        // Convert the array to a vector
        vector<int> vec(nums, nums + n);
        return findPeakElement(vec);
    }
};