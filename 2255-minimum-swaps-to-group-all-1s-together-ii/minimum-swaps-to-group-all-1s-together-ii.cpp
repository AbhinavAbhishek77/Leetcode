class Solution {
public:
    int solveet(vector<int>& nums) {
        int totalOnes = 0;
        for (int num : nums) {
            totalOnes += num;
        }

        if (totalOnes == 0 || totalOnes == 1) {
            return 0;
        }

        vector<int> extendedArr(nums.begin(), nums.end());
        extendedArr.insert(extendedArr.end(), nums.begin(), nums.end());

        int onesInWindow = 0;
        for (int i = 0; i < totalOnes; ++i) {
            onesInWindow += extendedArr[i];
        }
        int maxOnesInWindow = onesInWindow;

        for (int i = 1; i < nums.size(); ++i) {
            onesInWindow = onesInWindow - extendedArr[i - 1] +
                           extendedArr[i + totalOnes - 1];
            maxOnesInWindow = max(maxOnesInWindow, onesInWindow);
        }

        return totalOnes - maxOnesInWindow;
    }
    int minSwaps(vector<int>& nums) { return solveet(nums); }
};