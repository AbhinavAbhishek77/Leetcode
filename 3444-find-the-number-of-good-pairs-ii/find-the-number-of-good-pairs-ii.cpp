class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> mp;
        for (auto v : nums1) {
            for (int i = 1; i * i <= v; i++) {
                if (i * i == v) {
                    mp[i]++;
                } else if (v % i == 0) {
                    mp[i]++;
                    mp[v / i]++;
                }
            }
        }

        long long int res = 0;
        for (auto v : nums2) {
            v *= k;
            if (mp[v] > 0) {
                res += mp[v];
            }
        }

        return res;
    }
};