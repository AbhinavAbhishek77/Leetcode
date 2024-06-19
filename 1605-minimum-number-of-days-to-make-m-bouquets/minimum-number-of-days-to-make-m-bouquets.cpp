class Solution {
public:
    long long countBouquets(vector<int>& a, int days, int k) {
        long long t = 0;
        long long c = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] <= days) {
                c++;
                if (c == k) {
                    t++;
                    c = 0;
                }
            } else {
                c = 0;
            }
        }
        return t;
    }

    long long s1(vector<int>& a, int m, int k) {
        long long left = 1;
        long long right = 0;
        for(auto v : a)
            right += v;
        long long ans = -1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long t = countBouquets(a, mid, k);

            if (t < m) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        return s1(bloomDay, m, k);
    }
};