class Solution {
    public List<String> summaryRanges(int[] nums) {
       ArrayList<String> res = new ArrayList<String>();
    int st = 0;
    for(int i = 1; i <= nums.length; i++) {
        if(i == nums.length || nums[i] != nums[i - 1] + 1) {
            res.add((st == i - 1) ? "" + nums[st] : nums[st] + "->" + nums[i - 1]);
            st = i;
        }
    }
    return res;  
    }
}