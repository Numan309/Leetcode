class Solution {
public:
    int maxOperations(vector<int>& nums) {
         int sum = nums[0]+nums[1];
        int cnt=0;
      for(int i=0;i<nums.size()-1;i=i+2){ // i+2 because i+1 will already process below
         if(nums[i]+nums[i+1]==sum) cnt++;
         else break;
      }
        return cnt;
    }
};