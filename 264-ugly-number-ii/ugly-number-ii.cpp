class Solution {
public:
    int solvee(int n) {
        vector<int> f = {2, 3, 5};
        unordered_set<long long> v;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        pq.push(1);
        v.insert(1);

        long long u = 1;
        for (int i = 0; i < n; ++i) {
            u = pq.top();
            pq.pop();

            if (i == n - 1) {
                return u;
            }

            for (int x : f) {
                long long nxt = u * x;
                if (v.find(nxt) == v.end()) {
                    v.insert(nxt);
                    pq.push(nxt);
                }
            }
        }
        return -1;
    }

    int nthUglyNumber(int n) { return solvee(n); }
};
