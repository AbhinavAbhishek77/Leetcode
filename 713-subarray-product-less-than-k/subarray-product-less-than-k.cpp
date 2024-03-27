class Solution {
public:
//TC==>O(n)
//SC==>O(1)
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 1)
            return 0;

        int i = 0, j = 0, cnt = 0, pro = 1;
        while (j < n) {
            pro *= nums[j];
            while (pro >= k) {
                pro /= nums[i];
                i++;
            }
            //This (j-i+1) tells how many subarrays ends at index j
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
};