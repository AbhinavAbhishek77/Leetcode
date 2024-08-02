class Solution {
public:
    // TC:O(ElogE)
    // SC: O(N)
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {

        // make adjacency list

        vector<pair<int, double>> adj[n];
        int i = 0;
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            double wt = succProb[i++];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        // for (int i = 0; i < n; i++) {
        //     for (auto v : adj[i])
        //         cout << v.first << " " << v.second << endl;
        // }

        // priority_queue<pair<double, int>> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        // queue<pair<double, int>> pq;

        vector<double> dist(n, 0);
        dist[start_node] = 1;
        pq.push({1, start_node});

        while (!pq.empty()) {
            int node = pq.top().second;
            double w = pq.top().first;
            pq.pop();

            for (auto it : adj[node]) {
                int nextNode = it.first;
                double weight = it.second;

                if (dist[node] * weight > dist[nextNode]) {
                    dist[nextNode] = dist[node] * weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        // for (auto v : dist) {
        //     cout << v << endl;
        // }
        return dist[end_node];
    }
};