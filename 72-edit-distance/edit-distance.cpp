class Solution {
public:
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
                    dp[i][j] = dp[i - 1][j - 1];
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
        return tabulation(word1, word2);
    }
};