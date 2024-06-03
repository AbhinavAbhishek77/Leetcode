class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();

        int hash[101] = {0};
        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < 101; i++) {
            int x = hash[i];

            // Use long long for the calculation to avoid overflow
            ans += (static_cast<long long>(x) * (x - 1)) / 2;
        }
        return ans;
    }
};