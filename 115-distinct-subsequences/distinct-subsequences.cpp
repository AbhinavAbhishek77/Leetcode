class Solution {
public:
    // Space optimized =>2D Array
    int mod = 1e9 + 7;
    // prev[0] = 1 means that there is exactly one way to match an empty
    // subsequence (sub) with any prefix of str. curr[0] = 1 ensures that this
    // property is carried over as we compute values for each new row.
    int distinctSubsequences(string& str, string& sub) {
        int n = str.size();
        int m = sub.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // for (int i = 0; i <= n; i++) {
        //     dp[i][0] = 1; // An empty sub is a subsequence of any string
        // }
        // for (int j = 1; j <= m; j++) {
        //     dp[0][j] = 0; // Non-empty sub cannot be a subsequence of an
        //     empty string
        // }

        prev[0] = curr[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str[i - 1] == sub[j - 1]) {
                    curr[j] = (prev[j - 1] + prev[j]) % mod;
                } else {
                    curr[j] = prev[j] % mod;
                }
            }
            prev = curr;
        }

        return prev[m] % mod;
    }

    int numDistinct(string s, string t) { return distinctSubsequences(s, t); }
};