class Solution {
public:
    int solve(vector<int>& nums, int ind, int target, vector<vector<int>>& dp) {
        if (target == 0) {
            return 0;
        }
        if (ind == 0) {
            return target % nums[ind] == 0 ? target / nums[ind] : INT_MAX;
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        int notpick = solve(nums, ind - 1, target, dp);
        int pick = INT_MAX;
        if (nums[ind] <= target) {
            int res = solve(nums, ind, target - nums[ind], dp);
            if (res != INT_MAX) {
                pick = 1 + res;
            }
        }

        return dp[ind][target] = min(notpick, pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = solve(coins, n - 1, amount, dp);
        return result == INT_MAX ? -1 : result;
    }
};