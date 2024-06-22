class Solution {
public:
    long long int solve(vector<int>& coins, int N, int sum) {
        vector<vector<long long int>> dp(N, vector<long long int>(sum + 1, 0));

        for (int i = 0; i < N; i++) {
            dp[i][0] = 1;
        }

        for (int target = 0; target <= sum; target++) {
            if (target % coins[0] == 0)
                dp[0][target] = 1;
            else
                dp[0][target] = 0;
        }

        for (int ind = 1; ind < N; ind++) {
            for (int target = 0; target <= sum; target++) {
                long long int notpick = dp[ind - 1][target];
                long long int pick = 0;
                if (coins[ind] <= target) {
                    pick = dp[ind][target - coins[ind]];
                }
                dp[ind][target] = notpick + pick;
            }
        }

        return dp[N - 1][sum];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(coins, n, amount);
    }
};