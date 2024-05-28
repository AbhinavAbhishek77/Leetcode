class Solution {
public:
    int solve(string s, string t, int maxCost) {
        int n = s.size();
        int ml = 0;
        int i = 0, j = 0;
        int cost = 0;

        while (j < n) {
            cost += abs(s[j] - t[j]);

            if (cost > maxCost) {
                cost -= abs(s[i] - t[i]);
                i++;
            }

            ml = max(ml, j - i + 1);
            j++;
        }

        return ml;
    }
    int equalSubstring(string s, string t, int maxCost) {
        return solve(s,t,maxCost);
    }
};