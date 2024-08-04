class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7;
        vector<long long> arr;

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                arr.push_back(sum);
            }
        }

        sort(arr.begin(), arr.end());
        long long ans = 0;
        for (int i = left - 1; i <= right - 1; i++) {
            ans = ans % mod + arr[i];
        }

        return (int)ans;
    }
};