class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> mp(1001, 0);
        for (auto v : arr1) {
            mp[v]++;
        }
        int ind = 0;
        // Place elements of arr2 in their relative order
        for (int i = 0; i < arr2.size(); i++) {
            // if arr2[i] exists in mp
            if (mp[arr2[i]] != 0) {
                int k = mp[arr2[i]];
                while (k--) {
                    arr1[ind++] = arr2[i];
                }
                mp[arr2[i]] = 0; // Mark as processed
            }
        }
        // Place remaining elements in ascending order
        for (int i = 0; i < 1001; i++) {
            if (mp[i] != 0) {
                int k = mp[i];
                while (k--) {
                    arr1[ind++] = i;
                }
            }
        }

        return arr1;
    }
};