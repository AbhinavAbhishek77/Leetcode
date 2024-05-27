class Solution {
public:
    int specialArray(vector<int>& nums) {
        // TC:O(N2)
        for (int i = 0; i <= 100; i++) {
            int x = i;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] >= x) {
                    cnt++;
                }
            }
            if (x == cnt) {
                return x;
            }
        }
        return -1;
    }
};