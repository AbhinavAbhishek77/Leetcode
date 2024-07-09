class Solution {
public:
    double solve(vector<vector<int>>& ans) {
        int n = ans.size();
        int p = ans[0][0];
        double s = 0.0;

        for (auto c : ans) {
            int a = c[0];
            int t = c[1];

            if (a > p) {
                p = a;
            }
            p += t;
            s += (p - a);
        }

        return s / n;
    }
    double averageWaitingTime(vector<vector<int>>& customers) {
        return solve(customers);
    }
};