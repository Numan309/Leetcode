class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> fruitCount; // Map to store the count of each fruit in the current window
        int left = 0, maxlen = 0;

        for (int right = 0; right < n; ++right) {
            // Add the current fruit to the window
            fruitCount[fruits[right]]++;

            // If the number of distinct fruits exceeds 2, shrink the window
            while (fruitCount.size() > 2) {
                fruitCount[fruits[left]]--;
                if (fruitCount[fruits[left]] == 0) {
                    fruitCount.erase(fruits[left]); // Remove fruit from map if count becomes zero
                }
                left++; // Shrink the window
            }

            // Update the maximum length of the valid subarray
            maxlen = max(maxlen, right - left + 1);
        }

        return maxlen;
    }
};
