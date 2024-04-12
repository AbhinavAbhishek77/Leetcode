class Solution {
public:
    int trappedWaterAmount(vector<int>& heights) {
        int a = heights.size();
        vector<int> b(a);
        b[0] = heights[0];
        for (int c = 1; c < a; c++) {
            b[c] = max(b[c - 1], heights[c]);
        }
        vector<int> d(a);
        d[a - 1] = heights[a - 1];
        for (int c = a - 2; c >= 0; c--) {
            d[c] = max(heights[c], d[c + 1]);
        }

        int e = 0;
        for (int c = 0; c < a; c++) {
            int f = min(b[c], d[c]);
            e += f - heights[c];
        }

        return e;
    }

    int trap(vector<int>& height) { return trappedWaterAmount(height); }
};