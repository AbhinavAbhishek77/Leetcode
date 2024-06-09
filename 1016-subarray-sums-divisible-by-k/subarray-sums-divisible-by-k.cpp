class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mapp;
        int add = 0;

         int ans = 0;
        mapp[0] = 1;
        

        for (int i = 0; i < n; i++) {
            add += nums[i];

            int rem = add % k;

            if (rem < 0) {
                rem += k;
            }
            if (mapp.find(rem) != mapp.end()) {
                ans += mapp[rem];
            }
            mapp[rem]++;
        }

        return ans;
    }
    int subarraysDivByK(vector<int>& nums, int k) { return solve(nums, k); }
};