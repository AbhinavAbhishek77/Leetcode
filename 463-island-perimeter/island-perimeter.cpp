class Solution {
public:
    int islandPerimeter12(vector<vector<int>>& newg) {
        int dc = newg[0].size();
        int as = 0;
        int dr = newg.size();

        for (int i = 0; i < dr; i++) {
            for (int j = 0; j < dc; j++) {
                if (newg[i][j] == 1) {
                    as += 4;
                    if (j > 0 && newg[i][j - 1] == 1)
                        as -= 2;

                    if (i > 0 && newg[i - 1][j] == 1)
                        as -= 2;
                }
            }
        }

        return as;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        return islandPerimeter12(grid);
    }
};