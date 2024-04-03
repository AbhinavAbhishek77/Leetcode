class Solution {
public:
    bool ddssdd(vector<vector<char>>& board, vector<vector<bool>>& ffdd,
             const string word, int index, int i, int j) {
        if (index == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            ffdd[i][j] || board[i][j] != word[index])
            return false;

        ffdd[i][j] = true;
        bool found = ddssdd(board, ffdd, word, index + 1, i + 1, j) ||
                     ddssdd(board, ffdd, word, index + 1, i - 1, j) ||
                     ddssdd(board, ffdd, word, index + 1, i, j + 1) ||
                     ddssdd(board, ffdd, word, index + 1, i, j - 1);
        ffdd[i][j] = false;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty())
            return false;

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> ffdd(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ddssdd(board, ffdd, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};