class Solution {
public:
    // TC:O(N)
    // SC:O(N)
    int space(vector<int>& nums, int ind) {
        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i <= ind; i++) {
            int pick = nums[i];
            if (i - 2 >= 0) {
                pick = nums[i] + prev2;
            }
            int notpick = 0 + prev;

            int curr = max(pick, notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> temp1(nums.begin(), nums.end() - 1),
            temp2(nums.begin() + 1, nums.end());

        return max(space(temp1, temp1.size() - 1),
                   space(temp2, temp2.size() - 1));
    }
};