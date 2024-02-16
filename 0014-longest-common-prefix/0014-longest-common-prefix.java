class Solution {
    public String longestCommonPrefix(String[] strs) {
      int minimum=strs[0].length() ;
      for(String s:strs){
          minimum=Math.min(minimum,s.length());
      }
      StringBuilder str=new StringBuilder();
      for(int i=0;i<minimum;i++){
          char temp=strs[0].charAt(i);
          for(int j=1;j<strs.length;j++){
              if(temp!=strs[j].charAt(i)){
                return str.toString();
              }
          }
               str.append(temp);     
      }
      return str.toString() ;
    }
}