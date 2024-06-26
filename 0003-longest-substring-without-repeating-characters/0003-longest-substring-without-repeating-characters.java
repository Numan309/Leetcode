class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxL = 0;
        int n = s.length();
        for(int i = 0;i<n;i++){
          int[] hash = new int[256]; 
            for(int j=i;j<n;j++){
                if(hash[s.charAt(j)] == 1)
                    break;
             int len = j-i+1;
                maxL = Math.max(len,maxL);
               hash[s.charAt(j)] = 1;
            }
        }
        return maxL;
    }
}