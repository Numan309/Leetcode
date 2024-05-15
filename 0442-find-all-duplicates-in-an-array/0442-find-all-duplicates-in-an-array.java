class Solution {
    public List<Integer> findDuplicates(int[] nums) {
       ArrayList<Integer> ans = new ArrayList<Integer>();
        HashSet<Integer> hs = new HashSet<Integer>();
        for(int i = 0 ; i < nums.length ; i++){
			//checking if it contains which means it is encounter second time
			//it given that there is strictly only one or two elements are present
            if(hs.contains(nums[i])){
                ans.add(nums[i]);
            }else{
                hs.add(nums[i]);
            }
        }
        return ans;
    }
}