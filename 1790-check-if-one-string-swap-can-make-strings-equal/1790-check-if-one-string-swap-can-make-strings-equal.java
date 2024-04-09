class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if (s1.equals(s2)) {
            return true; // If strings are already equal, no need for swapping
        }
        
        int firstDiffIndex = -1;
        int secondDiffIndex = -1;
        
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                if (firstDiffIndex == -1) {
                    firstDiffIndex = i;
                } else if (secondDiffIndex == -1) {
                    secondDiffIndex = i;
                } else {
                    return false; // More than two differing characters
                }
            }
        }
        
        return (secondDiffIndex != -1 && s1.charAt(firstDiffIndex) == s2.charAt(secondDiffIndex) &&
                s1.charAt(secondDiffIndex) == s2.charAt(firstDiffIndex));
    }
}