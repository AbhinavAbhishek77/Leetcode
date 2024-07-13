class Solution {
public:
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp) {

        if (i == 0)
            return j;
        if (j == 0)
            return i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i - 1] == t[j - 1]) {
            return dp[i][j] = solve(s, t, i - 1, j - 1, dp);
        } else {
            // insert
            // delete
            // replace
            return dp[i][j] = min(min(1 + solve(s, t, i, j - 1, dp),
                                      1 + solve(s, t, i - 1, j, dp)),
                                  1 + solve(s, t, i - 1, j - 1, dp));
        }
    }

    int tabulation(string& s, string& t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base Case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = solve(s, t, i - 1, j - 1, dp);
                } else {
                    // insert
                    // delete
                    // replace
                    dp[i][j] = min(min(1 + dp[i][j - 1], 1 + dp[i - 1][j]),
                                   1 + dp[i - 1][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(word1, word2, n, m, dp);
    }
};