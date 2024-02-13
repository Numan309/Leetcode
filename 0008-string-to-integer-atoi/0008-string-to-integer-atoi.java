class Solution {
    public int myAtoi(String s) {
        long res=0;
        int check=1;
        int ind=0;
        if(s.length()==0||s==null){
            return 0;
        }
        s=s.trim();
        if(s.length()==0){
            return 0;
        }
        if(s.charAt(0)=='-'||s.charAt(0)=='+'){
            ind++;
        }
        check=s.charAt(0)=='-'?-1:1;
        while(ind<s.length()&&Character.isDigit(s.charAt(ind))){
      res=res*10+s.charAt(ind)-'0';
      ind++;
      if(res*check>Integer.MAX_VALUE){
          return Integer.MAX_VALUE;
      }
      if(res*check<Integer.MIN_VALUE){
          return Integer.MIN_VALUE;
      }
      
        }
        return (int) res*check;
    }
}