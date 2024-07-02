class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // int a[1001] = {0};
        // int b[1001] = {0};

        // int n = nums1.size(), m = nums2.size();
        // for (int i = 0; i < n; i++) {
        //     a[nums1[i]]++;
        // }

        // for (int i = 0; i < m; i++) {
        //     b[nums2[i]]++;
        // }

        // vector<int> ans;
        // for (int i = 0; i < 1001; i++) {
        //     int mini = min(a[i], b[i]);
        //     for (int j = 0; j < mini; j++) {
        //         ans.push_back(i);
        //     }
        // }

        // return ans;

        unordered_map<int, int> countMap;
        vector<int> ans;

        // Count the elements in nums1
        for (int num : nums1) {
            countMap[num]++;
        }

        // Find intersections with nums2
        for (int num : nums2) {
            if (countMap[num] > 0) {
                ans.push_back(num);
                countMap[num]--;
            }
        }

        return ans;
    }
};