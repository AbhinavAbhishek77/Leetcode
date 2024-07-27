class Solution {
public:
    bool bfs(int src, vector<vector<int>>& adj, vector<int>& col) {
        col[src] = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});

        while (!q.empty()) {
            int node = q.front().first;
            int color = q.front().second;
            q.pop();

            for (auto it : adj[node]) {
                // not colored
                if (col[it] == -1) {
                    col[it] = !color;
                    q.push({it, col[it]});
                } else // colored
                {
                    if (col[it] == color) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> col(V, -1);
        for (int i = 0; i < V; i++) {
            if (col[i] == -1) {
                if (!bfs(i, graph, col)) {
                    return false;
                }
            }
        }

        return true;
    }
};