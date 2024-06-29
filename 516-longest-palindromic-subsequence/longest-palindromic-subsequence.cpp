class Solution {
public:
    // Tab

    int lcs(string &s, string &t) {
        int n = s.size(), m = t.size();
        int i1 = n, i2 = m;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // base case
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return lcs(t, s);
    }
};