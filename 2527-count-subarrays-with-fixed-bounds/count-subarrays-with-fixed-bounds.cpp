class Solution {
public:
    long long solve(vector<int>& nums, int minK, int maxK) {
        int length = nums.size();
        long long result = 0;
        int maxIndex = -1;
        int minIndex = -1;
        int startIndex = 0;
        for (int i = 0; i < length; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                minIndex = maxIndex = -1;
                startIndex = i + 1;
            }
            if (nums[i] == minK) {
                minIndex = i;
            }
            if (nums[i] == maxK) {
                maxIndex = i;
            }
            result += max(min(minIndex, maxIndex) - startIndex + 1, 0);
        }
        return result;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        return solve(nums, minK, maxK);
    }
};