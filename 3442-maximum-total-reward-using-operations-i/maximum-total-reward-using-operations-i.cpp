class Solution {
public:
  

int solve(vector<int>& rewardValues, int ind, vector<vector<int>>& dp, int x) {
    if (ind == rewardValues.size()) {
        return 0;
    }
    if (dp[ind][x] != -1) {
        return dp[ind][x];
    }

    int pick = 0;
    if (rewardValues[ind] > x) {
        pick = rewardValues[ind] + solve(rewardValues, ind + 1, dp, x + rewardValues[ind]);
    }
    int notpick = solve(rewardValues, ind + 1, dp, x);

    return dp[ind][x] = max(pick, notpick);
}

int maxTotalReward(vector<int>& rewardValues) {
    int n = rewardValues.size();
    sort(rewardValues.begin(), rewardValues.end());
    
    // Assuming the maximum possible sum of rewards is 10000 for this example
    int maxPossibleSum = 10000;
    vector<vector<int>> dp(n, vector<int>(maxPossibleSum + 1, -1));

    return solve(rewardValues, 0, dp, 0);
}

};