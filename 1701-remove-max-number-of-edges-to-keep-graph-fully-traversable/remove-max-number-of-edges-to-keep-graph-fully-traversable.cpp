class Solution {
public:
    int find(vector<int>& d, int a) {
        if (d[a] != a) {
            d[a] = find(d, d[a]);
        }
        return d[a];
    }

    void unite(vector<int>& d, int a, int b) {
        int A = find(d, a);
        int B = find(d, b);
        if (A > B) {
            d[A] = B;
        } else {
            d[B] = A;
        }
    }

    void processEdges(int n, vector<vector<int>>& e, vector<int>& d, int& r) {
        for (const auto& ed : e) {
            int w = ed[0], s = ed[1] - 1, t = ed[2] - 1;
            if (w & 1) {
                if (find(d, s) == find(d, t)) {
                    r++;
                } else {
                    unite(d, s, t);
                }
            }
            if (w & 2) {
                if (find(d, s + n) == find(d, t + n) &&
                    (w == 2 || find(d, s) != find(d, t))) {
                    r++;
                } else {
                    unite(d, s + n, t + n);
                }
            }
        }
    }

    bool isConnected(int n, vector<int>& d) {
        for (int i = 0; i < 2 * n; ++i) {
            find(d, i);
        }

        unordered_map<int, int> cnt;
        for (const auto& p : d) {
            cnt[p]++;
        }

        return cnt.size() == 2;
    }

    int solve(int n, vector<vector<int>>& e) {
        vector<int> d(2 * n);
        iota(d.begin(), d.end(), 0);

        int r = 0;

        sort(e.begin(), e.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] > b[0];
             });

        processEdges(n, e, d, r);

        if (!isConnected(n, d)) {
            return -1;
        }

        return r;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        return solve(n, edges);
    }
};