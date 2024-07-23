class Solution {
   public char findTheDifference(String s, String t) {
    int n = s.length(); 
    int m = t.length(); 
    
    char result = 0; 

    // XOR all characters from both strings
    for (int i = 0; i < n; i++) {
        result ^= s.charAt(i);
    }
    for (int j = 0; j < m; j++) {
        result ^= t.charAt(j);
    }
    
    return result; 
}

}