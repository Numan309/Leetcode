class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int start = 0,end = nums.size()-1;
        unordered_set<int> seen;
    for(int i = 0; i < nums.size(); i++) {
        if(seen.count(nums[i]) > 0) {
            return true;
        }
        seen.insert(nums[i]);
    }
    return false;
    }
};