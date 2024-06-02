class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin(), s.end());

        int st = 0, e = s.size() - 1;

        while (st <= e) {
            swap(s[st], s[e]);
            st++;
            e--;
        }
    }
};