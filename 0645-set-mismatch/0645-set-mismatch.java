class Solution {
    public int[] findErrorNums(int[] nums) {
       int n = nums.length;
        int [] arr = new int[n+1];
        for(int i:nums){
            arr[i]++;
        }
            int [] res = new int [2];
            for(int i = 1;i<arr.length;i++){
            if(arr[i]==2){
                res[0]=i;
            }
                else if(arr[i]==0){
                    res[1]=i;
                }
            }
        return res;
        }
    
}