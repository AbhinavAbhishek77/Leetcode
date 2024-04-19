class Solution {
public:
    int countIslands(vector<vector<char>>& grid) 
    {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++)
         {
            for (int j = 0; j < grid[0].size(); j++)
             {
                if (grid[i][j] == '1')
                 {
                    markIsland(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }

    void markIsland(vector<vector<char>>& grid, int row, int col)
     {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
            grid[row][col] == '0') 
            {
            return;
        }
        grid[row][col] = '0';
        markIsland(grid, row + 1, col);
        markIsland(grid, row - 1, col);
        markIsland(grid, row, col + 1);
        markIsland(grid, row, col - 1);
    }

    int numIslands(vector<vector<char>>& grid) { return countIslands(grid); }
};