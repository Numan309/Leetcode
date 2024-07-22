class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int start = 1, end = position[n-1] - position[0]; // Initialize start and end variables
        int ans = 0; // Initialize ans variable to store the maximum distance found
        
        while (start <= end) { // Use <= in the condition to handle the case when start == end
            int mid = start + (end - start) / 2;
            int count = 1; // Initialize count of points with the first point as starting point
            int last_position = position[0]; // Track the last position where a point was placed
            
            for (int i = 1; i < n; i++) {
                if (position[i] - last_position >= mid) { // Check if current position can accommodate a new point
                    count++;
                    last_position = position[i]; // Update the last position where a point was placed
                }
            }
            
            if (count >= m) { // If we can place at least m points with at least mid distance apart
                ans = mid; // Update ans to the current mid
                start = mid + 1; // Try for a larger distance
            } else {
                end = mid - 1; // Try for a smaller distance
            }
        }
        
        return ans;
    }
};
