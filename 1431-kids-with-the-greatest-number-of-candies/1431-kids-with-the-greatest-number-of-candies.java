class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
       int max = 0;
        List<Boolean> res = new ArrayList<>();
        for(int j =0;j<candies.length;j++){
           if(candies[j]>max)max=candies[j];
        }
        for(int i =0;i<candies.length;i++){
            if(candies[i]+extraCandies>=max){
            res.add(true);
            }
            else res.add(false);
        }
        return res;
    }
}