class Solution {
public:
    bool mem(vector<int>& arr, int ind, int target, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target == 0)
                return true;
            else
                return false;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool pick = false;
        if (arr[ind] <= target) {
            pick = mem(arr, ind - 1, target - arr[ind], dp);
        }
        bool notpick = mem(arr, ind - 1, target, dp);

        return dp[ind][target] = pick | notpick;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (auto v : nums)
            totalSum += v;
        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return mem(nums, n - 1, target, dp);
    }
};