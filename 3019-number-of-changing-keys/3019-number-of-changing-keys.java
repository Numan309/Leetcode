class Solution {
    public int countKeyChanges(String s) {
        s = s.toLowerCase();
        int cnt = 0;
        int n = s.length();
        for(int i=1; i<n;i++){
            if(s.charAt(i)!=s.charAt(i-1)) cnt++;
        }
        return cnt;
    }
}