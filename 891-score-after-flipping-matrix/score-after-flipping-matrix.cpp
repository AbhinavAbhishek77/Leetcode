class Solution {
public:
    void tr(vector<vector<int>>& grid, int row) {
        for (int j = 0; j < grid[row].size(); ++j) {
            grid[row][j] ^= 1;
        }
    }

    void tc(vector<vector<int>>& grid, int col) {
        for (int i = 0; i < grid.size(); ++i) {
            grid[i][col] ^= 1;
        }
    }

    int matrixScore2(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                tr(grid, i);
            }
        }

        for (int j = 1; j < n; ++j) {
            int countOnes = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 1) {
                    ++countOnes;
                }
            }
            if (countOnes < m - countOnes) {
                tc(grid, j);
            }
        }

        int score = 0;
        for (int i = 0; i < m; ++i) {
            int rowVal = 0;
            for (int j = 0; j < n; ++j) {
                rowVal = rowVal * 2 + grid[i][j];
            }
            score += rowVal;
        }

        return score;
    }

    int matrixScore(vector<vector<int>>& grid) { return matrixScore2(grid); }
};