class Solution {
public:
    int singleNumber(vector<int>& nums) {
           unordered_map<int, int> count;
        
        // Count the occurrences of each number
        for (int num : nums) {
            count[num]++;
        }
        
        // Find the first unique number
        for (const auto& pair : count) {
            if (pair.second == 1) {
                return pair.first;  // Return the first unique number found
            }
        }
        
        return -1;  
    }
};