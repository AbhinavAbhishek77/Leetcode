class Solution {
public:
    int tabulation(string& s, string& t) {
        int n = s.size(), m = t.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Base Case
        // for (int i = 0; i <= n; i++) {
        //     curr[0] = i;
        // }

        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++) {
            curr[0]=i;
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    // insert
                    // delete
                    // replace
                    curr[j] =
                        min(min(1 + curr[j - 1], 1 + prev[j]), 1 + prev[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }
    int minDistance(string word1, string word2) {
        return tabulation(word1, word2);
    }
};