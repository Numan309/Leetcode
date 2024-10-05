class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
  int n = arr.size();
        vector<int> currXor(n, 0);
        
        // Initialize currXor with the first element
        currXor[0] = arr[0];
        for (int i = 1; i < n; i++) {
            currXor[i] = currXor[i - 1] ^ arr[i];
        }
        
        vector<int> v;
        for (const vector<int>& q : queries) {
            int left = q[0];
            int right = q[1];
            
            // Calculate the XOR for the query range
    int xor_res = currXor[right] ^ (left == 0 ? 0 : currXor[left - 1]);
            v.push_back(xor_res);
        }
        
        return v;
    }
};