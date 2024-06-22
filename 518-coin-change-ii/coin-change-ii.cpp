class Solution {
public:
    int solve(vector<int>& nums, int ind, int target, vector<vector<int>>& dp) {
        if (target == 0)
            return 1;
        if (ind == 0) {
            return target % nums[0] == 0 ? 1 : 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notpick = 0 + solve(nums, ind - 1, target, dp);
        int pick = 0;
        if (nums[ind] <= target) {
            pick = solve(nums, ind, target - nums[ind], dp);
        }

        return dp[ind][target] = notpick + pick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(coins, n - 1, amount, dp);
    }
};