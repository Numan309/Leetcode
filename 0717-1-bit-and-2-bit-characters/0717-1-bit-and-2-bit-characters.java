class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length;
        for (int i = 0; i < n; i++) {
            if (bits[i] == 1) 
                i++; 
            else{ 
                if (i == n - 1 && bits[i] == 0) 
                    return true; 
            }
        }
        return false;
    }
}