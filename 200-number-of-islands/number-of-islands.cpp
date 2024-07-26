class Solution {
public:
    void bfsSolve2(int startRow, int startCol, vector<vector<int>>& visited,
                   vector<vector<char>>& grid) {
        // Mark the starting node as visited
        visited[startRow][startCol] = 1;
        queue<pair<int, int>> q;
        // Push the starting node into the queue
        q.push({startRow, startCol});
        int numRows = grid.size();
        int numCols = grid[0].size();
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        // Until the queue becomes empty
        while (!q.empty()) {
            int currentRow = q.front().first;
            int currentCol = q.front().second;
            q.pop();

            // Traverse the neighbors and mark them if they are land
            for (int k = 0; k < 4; k++) {
                int newrow = currentRow + delrow[k];
                int newcol = currentCol + delcol[k];

                if (newrow >= 0 && newrow < numRows && newcol >= 0 &&
                    newcol < numCols && grid[newrow][newcol] == '1' &&
                    !visited[newrow][newcol]) {
                    visited[newrow][newcol] = 1;
                    q.push({newrow, newcol});
                }
            }
        }
    }

    // Function to find the number of islands.
    int solve1(vector<vector<char>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        // Create visited array and initialize to 0
        vector<vector<int>> visited(numRows, vector<int>(numCols, 0));
        int islandCount = 0;
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                // If the cell is not visited and is land
                if (!visited[row][col] && grid[row][col] == '1') {
                    islandCount++;
                    bfsSolve2(row, col, visited, grid);
                }
            }
        }
        return islandCount;
    }
    int numIslands(vector<vector<char>>& grid) { return solve1(grid); }
};