class Solution {
public:
    int solve(int index, vector<int>& dp) {
        // Base cases
        if (index == 0)
            return 1;
        if (index < 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];

        // doing all the stuffs on the index acc. to problem
        int left = solve(index - 1, dp);
        int right = solve(index - 2, dp);

        return dp[index] = left + right;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};