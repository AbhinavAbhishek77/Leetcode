class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //TC: O(N)
        //SC:O(1)
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {

            for (int j = 0; j < nums2.size(); j++) {
                int x = nums2[j] * k;
                if (nums1[i] % x == 0)
                    ans++;
            }
        }
        return ans;
    }
};