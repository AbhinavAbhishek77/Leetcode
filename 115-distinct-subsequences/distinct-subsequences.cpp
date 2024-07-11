class Solution {
public:
    // Tabulation
    //  1-based indexing
    int mod = 1e9 + 7;
    // dp[i][j] means Count of all distinct subsequences of S2[0...j-1]
    // in the string S1[0...i-1].
    int distinctSubsequences(string& str, string& sub) {
        int n = str.size();
        int m = sub.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1; // An empty sub is a subsequence of any string
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] =
                0; // Non-empty sub cannot be a subsequence of an empty string
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str[i - 1] == sub[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                } else {
                    dp[i][j] = dp[i - 1][j] % mod;
                }
            }
        }

        return dp[n][m];
    }

    int numDistinct(string s, string t) { return distinctSubsequences(s, t); }
};