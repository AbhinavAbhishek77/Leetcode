class Solution {
public:
    // TC==>O(n)
    // SC==>O(n)
    int solve(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int i = 0, j = 0;
        int cnt = 0;
        int result = 0;

        while (j < n) {
            mp[nums[j]]++;

            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            // subarrays ending at j
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
            // We are getting the subarrays for k=k-1 also
            // but we dont need that so we handled that case by subtracting cnt corresponding to k=1
        int ans = solve(nums, k) - solve(nums, k - 1);
        return ans;
    }
};