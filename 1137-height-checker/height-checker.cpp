class Solution {
public:
//TC: O(nlogn)
//SC: O(100)
    int heightChecker(vector<int>& heights) {
        vector<int> ans(100, INT_MAX);
        for (int i = 0; i < heights.size(); i++) {
            ans[i] = heights[i];
        }

        sort(ans.begin(), ans.end());
        int cnt = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != ans[i])
                cnt++;
        }
        return cnt;
    }
};