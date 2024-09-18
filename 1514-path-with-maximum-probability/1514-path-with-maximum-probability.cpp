class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> adj;
        
        // Build the adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        
        vector<double> dist(n, 0.0); // Probabilities initialized to 0
        dist[start_node] = 1.0; // Start node has a probability of 1
        priority_queue<pair<double, int>> pq; // Max-heap for probabilities
        pq.push({1.0, start_node});
        
        while (!pq.empty()) {
            double currProb = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // If we reach the end node, return its probability
            if (node == end_node) {
                return currProb;
            }
            
            // Explore neighbors
            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                double weight = neighbor.second;
                
                // Calculate new probability
                double newProb = currProb * weight;
                
                // If the new probability is greater, update and push to the queue
                if (newProb > dist[nextNode]) {
                    dist[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }
        
        return 0.0; // If there's no path to end_node
    }
};