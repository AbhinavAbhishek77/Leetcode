class Solution {
public:
    int ss(vector<int>& c, vector<int>& g, int m) {
        int n = c.size();
        int total = 0;

        // Calculate the initial satisfaction without using the technique
        for (int i = 0; i < n; i++) {
            if (g[i] == 0) {
                total += c[i];
            }
        }

        // Calculate the maximum extra satisfied customers when using the
        // technique
        int extra = 0;
        int currentExtra = 0;

        // Initial window of size `m`
        for (int i = 0; i < m; i++) {
            if (g[i] == 1) {
                currentExtra += c[i];
            }
        }
        extra = currentExtra;

        // Slide the window across the entire array
        for (int i = m; i < n; i++) {
            if (g[i] == 1) {
                currentExtra += c[i];
            }
            if (g[i - m] == 1) {
                currentExtra -= c[i - m];
            }
            extra = max(extra, currentExtra);
        }

        return total + extra;
    }
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        return ss(customers, grumpy, minutes);
        // if (n == 1)
        //     return customers[0];

        // vector<int> ans(n);
        // int maxi = INT_MIN;
        // int ind = -1;

        // for (int i = 0; i < n; i++) {
        //     int add = 0;
        //     for (int j = i; j < n && j < minutes + i; j++) {
        //         if(grumpy[j]==1)
        //         add += customers[j];
        //     }
        //     ans[i] = add;
        //     if (grumpy[i]==1 && ans[i] > maxi) {
        //         maxi = ans[i];
        //         ind = i;
        //     }
        // }

        // int maxsuminds = ind;
        // int maxsuminde = ind + minutes - 1;

        // int sum = 0;
        // // maximum sum zone, where technique is used
        // sum += ans[maxsuminds];

        // // before maximum sum zone
        // for (int i = 0; i < maxsuminds; i++) {
        //     if (grumpy[i] != 1) {
        //         sum += customers[i];
        //     }
        // }
        // // after maximum sum zone
        // for (int i = maxsuminde + 1; i < n; i++) {
        //     if (grumpy[i] != 1) {
        //         sum += customers[i];
        //     }
        // }

        // return sum;
    }
};