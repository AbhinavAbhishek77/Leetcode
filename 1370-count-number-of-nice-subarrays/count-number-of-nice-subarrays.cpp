class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] %= 2;
        }
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currsum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            currsum += nums[i];
            if (currsum >= k) {
                cnt += mp[currsum - k];
            }
            mp[currsum]++;
        }
        return cnt;
    }
};