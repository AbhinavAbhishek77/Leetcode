class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int arr[201] = {0};
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i] + 100]++;
        }

        auto compare = [&](int a, int b) {
            if (arr[a + 100] == arr[b + 100])
                return a > b;
            else
                return arr[a + 100] < arr[b + 100];
        };
        sort(nums.begin(), nums.end(), compare);
        return nums;
    }
};