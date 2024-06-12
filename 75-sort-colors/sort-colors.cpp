class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (auto v : nums) {
            if (v == 0)
                cnt0++;
            else if (v == 1)
                cnt1++;
            else
                cnt2++;
        }

        int j = 0;
        while (j < nums.size() && cnt0--) {
            nums[j++] = 0;
        }

        while (j < nums.size() && cnt1--) {
            nums[j++] = 1;
        }

        while (j < nums.size() && cnt1--) {
            nums[j++] = 2;
        }
    }
};