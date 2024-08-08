class Solution {
public:
    vector<vector<int>> solve(int r, int c, int sr, int sc) {
        return solve2(r, c, sr, sc);
    }
    vector<vector<int>> solve2(int r, int c, int sr, int sc) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int cr = sr, cc = sc, cnt = 1, d = 0;
        vector<vector<int>> path;

        while (path.size() < r * c) {
            for (int i = 0; i < 2; ++i) {
                int dr = dir[d][0], dc = dir[d][1];
                for (int j = 0; j < cnt; ++j) {
                    if (cr >= 0 && cr < r && cc >= 0 && cc < c) {
                        path.push_back({cr, cc});
                    }
                    cr += dr;
                    cc += dc;
                }
                d = (d + 1) % 4;
            }
            cnt++;
        }

        return path;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        return solve(rows, cols, rStart, cStart);
    }
};