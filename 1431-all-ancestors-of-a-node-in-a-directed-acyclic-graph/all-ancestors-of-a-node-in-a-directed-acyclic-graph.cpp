class Solution {
public:
    void buildGraph(int n,  vector<vector<int>>& e, vector<vector<int>>& g,
                    vector<int>& in) {
        for (const auto& edge : e) {
            int u = edge[0];
            int v = edge[1];
            g[u].push_back(v);
            in[v] += 1;
        }
    }

    queue<int> initQueue(int n, vector<int>& in) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        return q;
    }

    void findAncestors(int n, const vector<vector<int>>& g, vector<set<int>>& a, vector<int>& in, queue<int>& q) {
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int next : g[node]) {
                a[next].insert(node);
                a[next].insert(a[node].begin(), a[node].end());
                in[next] -= 1;
                if (in[next] == 0) {
                    q.push(next);
                }
            }
        }
    }

    vector<vector<int>> convertToSortedVectors(int n, vector<set<int>>& a) {
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = vector<int>(a[i].begin(), a[i].end());
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }

    vector<vector<int>> solve(int n, vector<vector<int>>& e) {
        vector<vector<int>> g(n);
        vector<set<int>> a(n);
        vector<int> in(n, 0);

        buildGraph(n, e, g, in);
        queue<int> q = initQueue(n, in);
        findAncestors(n, g, a, in, q);

        return convertToSortedVectors(n, a);
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        return solve(n, edges);
    }
};