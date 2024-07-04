class Solution {
public:
    // Tab
    // dp[i][j] ==> till index [i][j] longest palindromic subsequence
    int minimumInsertions(string& str) {
        int n = str.size();

        string ptr = str;
        reverse(str.begin(), str.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Base condn already satisfied while declaring dp

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (ptr[i - 1] == str[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return n - dp[n][n];
    }
    int minInsertions(string s) { return minimumInsertions(s); }
};