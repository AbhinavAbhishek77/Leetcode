class Solution {
public:
    int solve(string &s, string &t, int i1, int i2, vector<vector<int>>& dp) {
        if (i1 == 0 || i2 == 0) {
            return 0;
        }
        if (dp[i1][i2] != -1) {
            return dp[i1][i2];
        }

        if (s[i1 - 1] == t[i2 - 1]) {
            return 1 + solve(s, t, i1 - 1, i2 - 1, dp);
        } else {
            return dp[i1][i2] = max(solve(s, t, i1, i2 - 1, dp),
                                    solve(s, t, i1 - 1, i2, dp));
        }
    }

    int lcs(string &s, string &t) {
        int n = s.size(), m = t.size();
        int i1 = n, i2 = m;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(s, t, i1, i2, dp);
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return lcs(t, s);
    }
};