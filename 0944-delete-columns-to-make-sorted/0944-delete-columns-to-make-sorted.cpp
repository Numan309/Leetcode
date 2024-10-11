class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int cnt = 0;
        
        for(int i = 0; i < m; i++) { // Iterate over each column
            for(int j = 1; j < n; j++) { // Compare with the previous string
                if(strs[j][i] < strs[j - 1][i]) { // If not sorted
                    cnt++; // Count the column for deletion
                    break; // No need to check further, move to next column
                }
            }
        }
        
        return cnt; // Return the number of columns to delete
    }
};
