class Solution {
public:
    int solve(vector<int>& d, vector<int>& c, int ind, int x, int mini,
              vector<vector<int>>& dp) {
        if (ind == d.size() - 1) {
            return d[ind] > x ? mini : 0;
        }
        if (dp[ind][x] != -1)
            return dp[ind][x];

        int p1 = INT_MAX;
        int p7 = INT_MAX;
        int p30 = INT_MAX;
        int y = INT_MAX;
        if (x >= d[ind]) {
            y = solve(d, c, ind + 1, x, mini, dp);
        } else {
            p1 = c[0] + solve(d, c, ind + 1, d[ind] + 1 - 1, mini, dp);
            p7 = c[1] + solve(d, c, ind + 1, d[ind] + 7 - 1, mini, dp);
            p30 = c[2] + solve(d, c, ind + 1, d[ind] + 30 - 1, mini, dp);
        }

        return dp[ind][x] = min(y, min(min(p1, p7), p30));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int mini = min(costs[0], min(costs[1], costs[2]));
        vector<vector<int>> dp(n + 1, vector<int>(1001, -1));
        return solve(days, costs, 0, days[0] - 1, mini, dp);
    }
};