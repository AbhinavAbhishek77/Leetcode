class Solution {
public:
    bool cv(vector<int>& p, int m, int d) {
        int c = 1;
        int lastP = p[0];
        for (int i = 1; i < p.size(); i++) {
            if (p[i] - lastP >= d) {
                c++;
                lastP = p[i];
                if (c == m) {
                    return true;
                }
            }
        }
        return false;
    }

    int solve(vector<int>& p, int m) {
        sort(p.begin(), p.end());
        int l = 1;
        int r = p.back() - p[0];
        int res = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (cv(p, m, mid)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
    int maxDistance(vector<int>& position, int m) {
        return solve(position, m);

        // int n = position.size();
        // sort(position.begin(), position.end());
        // vector<int> ans;
        // ans.push_back(position[0]);
    }
};