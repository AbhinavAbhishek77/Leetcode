class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // int row = grid.size();
        // int col = grid[0].size();

        // if (row < 3 || col < 3)
        //     return 0;

        // int cnt = 0;
        // for (int i = 0; i <= row - 3; i++) {
        //     for (int j = 0; j <= col - 3; j++) {
        //         int rows1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        //         int rows2 =
        //             grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
        //         int rows3 =
        //             grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

        //         int cols1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
        //         int cols2 =
        //             grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
        //         int cols3 =
        //             grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
        //         int diags1 =
        //             grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        //         int diags2 =
        //             grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];

        //         if (rows1 == rows2 && rows2 == rows3 && rows3 == diags1 &&
        //             diags1 == diags2 && diags2 == cols1 && cols1 == cols2 &&
        //             cols2 == cols3) {
        //             cnt++;
        //         }
        //     }
        // }

        // return cnt;

        int row = grid.size();
        int col = grid[0].size();

        if (row < 3 || col < 3)
            return 0;

        int cnt = 0;

        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= col - 3; j++) {
                if (grid[i + 1][j + 1] != 5)
                    continue;

                int rows1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                int rows2 =
                    grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
                int rows3 =
                    grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

                int cols1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
                int cols2 =
                    grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
                int cols3 =
                    grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];

                int diags1 =
                    grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                int diags2 =
                    grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];

                if (rows1 == 15 && rows2 == 15 && rows3 == 15 && cols1 == 15 &&
                    cols2 == 15 && cols3 == 15 && diags1 == 15 &&
                    diags2 == 15) {

                    vector<int> digits(10, 0);
                    bool isMagic = true;

                    for (int k = 0; k < 3; k++) {
                        for (int l = 0; l < 3; l++) {
                            int num = grid[i + k][j + l];
                            if (num < 1 || num > 9 || digits[num]++) {
                                isMagic = false;
                                break;
                            }
                        }
                        if (!isMagic)
                            break;
                    }

                    if (isMagic)
                        cnt++;
                }
            }
        }

        return cnt;
    }
};