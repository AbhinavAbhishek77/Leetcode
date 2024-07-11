class Solution {
public:
    // 1-based indexing
    int mod = 1e9 + 7;
    int solve(string& str, string& sub, int i, int j, vector<vector<int>>& dp) {
        if (j == 0)
            return 1;
        if (i == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j] % mod;

        if (str[i - 1] == sub[j - 1]) {
            return dp[i][j] = (solve(str, sub, i - 1, j - 1, dp) % mod +
                               solve(str, sub, i - 1, j, dp) % mod) %
                              mod;
        } else {
            return dp[i][j] = solve(str, sub, i - 1, j, dp) % mod;
        }
    }
    int distinctSubsequences(string& str, string& sub) {
        int n = str.size();
        int m = sub.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(str, sub, n, m, dp) % mod;
    }
    int numDistinct(string s, string t) { return distinctSubsequences(s, t); }
};