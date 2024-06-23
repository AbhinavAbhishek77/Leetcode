class Solution {
public:
    int solve(vector<int>& nums, int lim) {
        deque<int> maxD, minD;
        int i = 0, j = 0, maxLen = 0;

        while (j < nums.size()) {
            while (!maxD.empty() && maxD.back() < nums[j]) {
                maxD.pop_back();
            }
            while (!minD.empty() && minD.back() > nums[j]) {
                minD.pop_back();
            }

            maxD.push_back(nums[j]);
            minD.push_back(nums[j]);

            while (!maxD.empty() && !minD.empty() &&
                   maxD.front() - minD.front() > lim) {
                if (maxD.front() == nums[i]) {
                    maxD.pop_front();
                }
                if (minD.front() == nums[i]) {
                    minD.pop_front();
                }
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
    int longestSubarray(vector<int>& nums, int limit) {
        return solve(nums, limit);
    }
};