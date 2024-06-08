class Solution {
public:
    bool checkSubarraySumfind(vector<int>& numbers, int k) {

        unordered_map<int, int> rmp;
        rmp[0] = -1;
            int currsum = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            currsum += numbers[i];
            int currrem = currsum % k;
            if (currrem < 0) {
                currrem += k;
            }
            if (rmp.find(currrem) !=
                rmp.end()) {
                if (i - rmp[currrem] > 1) {
                    return true;
                }
            } else {
                rmp[currrem] = i;
            }
        }
        return false;
    }
    bool checkSubarraySum(vector<int>& nums, int k) {
        return checkSubarraySumfind(nums, k);
    }
};