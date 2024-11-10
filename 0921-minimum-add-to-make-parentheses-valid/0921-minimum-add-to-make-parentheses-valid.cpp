class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;  // To track unmatched '('
        int closeCount = 0; // To track unmatched ')'

        for (char ch : s) {
            if (ch == '(') {
                openCount++;
            } else if (ch == ')') {
                if (openCount > 0) {
                    // We can match one open '(' with this close ')'
                    openCount--;
                } else {
                    // No unmatched '(' to match this ')'
                    closeCount++;
                }
            }
        }

        // openCount will hold unmatched '('
        // closeCount will hold unmatched ')'
        return openCount + closeCount;
    }
};
