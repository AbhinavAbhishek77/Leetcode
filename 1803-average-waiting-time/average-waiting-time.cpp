class Solution {
public:
    double solve(vector<vector<int>>& ans) {
        int n = ans.size();
        double curr = ans[0][0];
        double wt = 0;
        for (auto v : ans) {
            if (curr >= v[0]) {
                curr += v[1];
                wt += curr - v[0];
            } else {
                curr = v[0] + v[1];
                wt += v[1];
            }
        }
        return wt / n;
    }
    double averageWaitingTime(vector<vector<int>>& customers) {
        return solve(customers);
    }
};