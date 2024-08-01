class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (auto v : details) {
            int a = v[11] - '0';
            int b = v[12] - '0';
            if ((int)(a * 10 + b) > 60)
                cnt++;
        }

        return cnt;
    }
};