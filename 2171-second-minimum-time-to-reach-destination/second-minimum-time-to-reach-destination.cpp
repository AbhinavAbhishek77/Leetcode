class Solution {
public:
    vector<vector<int>> solve(int n, vector<vector<int>>& edg) {
        vector<vector<int>> g(n + 1);
        for (auto& e : edg) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return g;
    }

    int solve2(int n, vector<vector<int>>& g, int tm, int chg) {
        queue<pair<int, int>> q;
        q.push({1, 0});
        vector<vector<int>> mt(n + 1, vector<int>(2, INT_MAX));
        mt[1][0] = 0;

        while (!q.empty()) {
            auto [i, pt] = q.front();
            q.pop();
            int ncs = pt / chg;
            int wt = (ncs % 2 == 0) ? 0 : chg - (pt % chg);
            int nt = pt + wt + tm;

            for (int j : g[i]) {
                if (nt < mt[j][0]) {
                    mt[j][0] = nt;
                    q.push({j, nt});
                } else if (mt[j][0] < nt && nt < mt[j][1]) {
                    if (j == n)
                        return nt;
                    mt[j][1] = nt;
                    q.push({j, nt});
                }
            }
        }

        return -1;
    }

    int solve1(int n, vector<vector<int>>& edg, int tm, int chg) {
        vector<vector<int>> g = solve(n, edg);
        return solve2(n, g, tm, chg);
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        return solve1(n, edges, time, change);
    }
};