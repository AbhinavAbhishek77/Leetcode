class Solution {
public:
    // TC:O(ElogE)
    // SC: O(N)
    // Function to find the maximum probability of reaching from start_node to
    // end_node
    // in a graph where edges have success probabilities instead of weights.
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {

        // Create an adjacency list where each node has a list of pairs
        // (neighbor, probability)
        vector<pair<int, double>> adj[n];
        int i = 0;
        for (auto it : edges) {
            int u = it[0];             // First node of the edge
            int v = it[1];             // Second node of the edge
            double wt = succProb[i++]; // Success probability of this edge
            adj[u].push_back({v, wt}); // Add the edge (u -> v) with weight
            adj[v].push_back(
                {u,
                 wt}); // Add the edge (v -> u) with weight (because undirected)
        }

        // Priority queue to store the nodes to be processed. The queue stores
        // pairs of (probability, node) and the maximum probability is at the
        // top of the queue.
        priority_queue<pair<double, int>> pq;

        // Vector to store the maximum probability to reach each node.
        vector<double> dist(n, 0);
        dist[start_node] = 1;     // Starting node has a probability of 1 (100%)
        pq.push({1, start_node}); // Push the start node into the priority queue

        // Process the nodes in the priority queue
        while (!pq.empty()) {
            int node =
                pq.top().second; // Get the node with the highest probability
            double w =
                pq.top().first; // Get the probability of reaching this node
            pq.pop();           // Remove the node from the priority queue

            // Explore all neighbors of the current node
            for (auto it : adj[node]) {
                int nextNode = it.first;   // Neighbor node
                double weight = it.second; // Probability of the edge from
                                           // current node to the neighbor

                // If the probability of reaching nextNode through the current
                // node is higher than any previously recorded probability,
                // update it.
                if (dist[node] * weight > dist[nextNode]) {
                    dist[nextNode] =
                        dist[node] *
                        weight; // Update the probability for nextNode
                    pq.push({dist[nextNode],
                             nextNode}); // Push the updated probability and
                                         // nextNode into the queue
                }
            }
        }

        // Return the maximum probability of reaching the end_node
        return dist[end_node];
    }
};