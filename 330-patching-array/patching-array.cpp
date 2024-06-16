class Solution {
public:
    int mp11(vector<int>& arr, int maxNum) {
        long long smallestM = 1;
        int patchC = 0, ind = 0;

        while (smallestM <= maxNum) {
            if (ind < arr.size() && arr[ind] <= smallestM) {
                smallestM += arr[ind++];
            } else {
                smallestM += smallestM;
                patchC++;
            }
        }
        return patchC;
    }

    int minPatches(vector<int>& nums, int n) { return mp11(nums, n); }
};