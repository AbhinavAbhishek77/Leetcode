class Solution {
public:
    long long solve(int n, vector<vector<int>>& roads) {
        vector<int> imp = calcImportance(n, roads);
        return calcTotalImportance(imp);
    }

    vector<int> calcImportance(int n, const vector<vector<int>>& roads) {
        vector<int> imp(n, 0);
        for (const auto& r : roads) {
            imp[r[0]]++;
            imp[r[1]]++;
        }
        return imp;
    }

    long long calcTotalImportance(vector<int>& imp) {
        sort(imp.begin(), imp.end());

        long long val = 1;
        long long res = 0;
        for (const auto& i : imp) {
            res += val * i;
            val++;
        }
        return res;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        return solve(n,roads);
    }
};