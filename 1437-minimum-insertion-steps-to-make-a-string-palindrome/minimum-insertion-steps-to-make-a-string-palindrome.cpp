class Solution {
public:
    // Mem
    int solve(int i, int j, string& ptr, string& str, vector<vector<int>>& dp) {
        if (i == 0 || j == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (ptr[i - 1] == str[j - 1]) {
            return dp[i][j] = 1 + solve(i - 1, j - 1, ptr, str, dp);
        } else {
            return dp[i][j] = max(solve(i, j - 1, ptr, str, dp),
                                  solve(i - 1, j, ptr, str, dp));
        }
    }

    int minimumInsertions(string& str) {
        int n = str.size();

        string ptr = str;
        reverse(str.begin(), str.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return n - solve(n, n, ptr, str, dp);
    }
    int minInsertions(string s) { return minimumInsertions(s); }
};