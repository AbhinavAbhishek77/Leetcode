class Solution {
public:
    // Kahn
    vector<int> topoSort(int V, vector<int> adj[]) {
        int indegree[V];
        for (int i = 0; i < V; i++)
            indegree[i] = 0;

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Check if topological sort is possible (i.e., no cycle in the graph)
        if (ans.size() != V) {
            return {}; // Return an empty vector if there's a cycle
        }

        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        for (auto v : adj) {
            for (auto x : v) {
                cout << x << " ";
            }
            cout << endl;
        }

        return topoSort(numCourses, adj);
    }
};