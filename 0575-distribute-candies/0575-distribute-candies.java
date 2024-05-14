class Solution {
    public int distributeCandies(int[] candyType) {
            HashSet<Integer> set = new HashSet<Integer>();
 
    for(int i = 0;i < candyType.length;i++) {
        set.add(candyType[i]);
      
    }
  int ans= Math.min(set.size(), candyType.length / 2);
    return ans;
    }
}