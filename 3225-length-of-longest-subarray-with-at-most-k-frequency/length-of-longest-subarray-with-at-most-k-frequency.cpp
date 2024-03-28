class Solution {
public:
    // TC==>O(n)
    // SC==>O(n)
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, maxi = INT_MIN;
        unordered_map<int, int> mp;

        while (j < n && i < n) {
            mp[nums[j]]++;

            while (mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }

            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};