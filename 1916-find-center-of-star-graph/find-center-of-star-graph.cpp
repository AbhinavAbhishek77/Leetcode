class Solution {
public:
    int solve(vector<vector<int>>& nums) {
        if (nums[0][0] == nums[1][0] || nums[0][0] == nums[1][1]) {
            return nums[0][0];
        } else {
            return nums[0][1];
        }
    }
    int findCenter(vector<vector<int>>& edges) { return solve(edges); }
};