class Solution {
    public boolean isPowerOfFour(int n) {
        //16/4=4(0). 4/4=1(0). true
        //5/4=1(1). false
      while(n>=4){
           if(n%4!=0)
           return false;
           n=n/4;
       }
       return n==1;
    }
}