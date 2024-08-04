class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      if (nums.size() <= 1) return false;

    // Sort the array
    sort(nums.begin(), nums.end());

    // Use two pointers to check for duplicates
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }

    return false;
    }
};