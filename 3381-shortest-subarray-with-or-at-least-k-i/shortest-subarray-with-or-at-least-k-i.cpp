class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        //TC==>O(n2)
        int n = nums.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            int orr = 0;
            for (int j = i; j < n; j++) {
                orr |= nums[j];
                if (orr >= k)
                    mini = min(mini, j - i + 1);
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};