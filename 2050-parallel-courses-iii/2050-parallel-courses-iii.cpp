class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
       // Create adjacency list and calculate in-degrees
        vector<vector<int>> adj(n);
        vector<int> inDeg(n, 0);

        for (int i = 0; i < relations.size(); ++i) {
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;
            adj[u].push_back(v);
            inDeg[v]++;
        }

        // Topological sort using for-loop approach
        vector<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.push_back(i);
            }
        }

        // Minimum time to complete courses
        vector<int> courseTime(n, 0);
        for (int idx = 0; idx < q.size(); ++idx) {
            int node = q[idx];
            for (int j = 0; j < adj[node].size(); ++j) {
                int neighbor = adj[node][j];
                inDeg[neighbor]--;
                if (inDeg[neighbor] == 0) {
                    q.push_back(neighbor);
                }
                courseTime[neighbor] = max(courseTime[neighbor], courseTime[node] + time[node]);
            }
        }

        // Calculate the minimum total completion time
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, courseTime[i] + time[i]);
        }
        return ans;
    }
};