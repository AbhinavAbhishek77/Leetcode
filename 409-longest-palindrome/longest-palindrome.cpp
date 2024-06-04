class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (auto v : s) {
            mp[v]++;
        }

        int cnt = 0;
        int singles = 0;
        for (auto v : mp) {
            int x = v.second;
            // if char occured at even number of times
            if (x % 2 == 0)
                cnt += x;
            // occured odd number of times or single time
            else {
                cnt += (x - 1);
                singles++;
            }
        }
        if (singles > 0)
            cnt += 1;
        return cnt;
    }
};