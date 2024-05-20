class Solution {
public:
    int solve1(vector<int>& ele) { return solve2(ele, 0, 0); }

    int solve2(vector<int>& ele, int pos, int curr) {
        if (pos == ele.size()) {
            return curr;
        }
        int inc = solve2(ele, pos + 1, curr ^ ele[pos]);
        int exc = solve2(ele, pos + 1, curr);
        return inc + exc;
    }

    int subsetXORSum(vector<int>& nums) { return solve1(nums); }
};