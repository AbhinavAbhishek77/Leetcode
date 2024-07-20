class Solution {
public:
    int calculateMin(int a, int b) { return min(a, b); }

    void updateSums(vector<int>& rS, vector<int>& cS, int i, int j, int val) {
        rS[i] -= val;
        cS[j] -= val;
    }

    void findNextIndices(vector<int>& rS, vector<int>& cS, int& i, int& j) {
        if (rS[i] == 0) {
            i++;
        }
        if (cS[j] == 0) {
            j++;
        }
    }

    vector<vector<int>> solve(vector<int>& rS, vector<int>& cS) {
        int n = rS.size();
        int m = cS.size();
        vector<vector<int>> res(n, vector<int>(m, 0));

        int i = 0, j = 0;
        while (i < n && j < m) {
            int x = calculateMin(rS[i], cS[j]);
            res[i][j] = x;

            updateSums(rS, cS, i, j, x);
            findNextIndices(rS, cS, i, j);
        }

        return res;
    }

    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        return solve(rowSum, colSum);
    }
};