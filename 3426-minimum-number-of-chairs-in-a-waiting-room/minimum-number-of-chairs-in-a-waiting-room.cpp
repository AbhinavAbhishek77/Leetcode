class Solution {
public:
    int minimumChairs(string s) {
        int cnt = 0;
        int maxi = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'E') {
                cnt++;
                maxi = max(maxi, cnt);
            } else {
                cnt--;
            }
        }
        return maxi;
    }
};