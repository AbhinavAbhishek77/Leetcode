class Solution {
public:
    int solve(vector<int>& nums, int k) {
        vector<int> d(nums.size(), 0);
        int c = 0;
        int r = 0;

        for (int i = 0; i <= nums.size() - k; i++) {
            if (flipIfNeeded(nums, d, c, i, k, r)) {
                r++;
            }
        }

        if (!validateRemaining(nums, d, c, k)) {
            return -1;
        }

        return r;
    }

    bool flipIfNeeded(vector<int>& nums, vector<int>& d, int& c, int i, int k,
                      int& r) {
        c ^= d[i];
        if (nums[i] == c) {
            if (i + k < nums.size()) {
                d[i + k] ^= 1;
            }
            c ^= 1;
            return true;
        }
        return false;
    }

    bool validateRemaining(vector<int>& nums, vector<int>& d, int& c, int k) {
        for (int i = nums.size() - k + 1; i < nums.size(); i++) {
            c ^= d[i];
            if (c == nums[i]) {
                return false;
            }
        }
        return true;
    }
    int minKBitFlips(vector<int>& nums, int k) { 
        return solve(nums, k);
         }
};