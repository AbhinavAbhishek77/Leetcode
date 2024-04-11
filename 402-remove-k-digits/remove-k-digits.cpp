class Solution {
public:
    string removeKdigits2(string num, int k) {
        vector<char> stt;
        for (char v : num) {
            while (!stt.empty() && stt.back() > v && k > 0) {
                stt.pop_back();
                k--;
            }
            stt.push_back(v);
        }
        while (k > 0) {
            stt.pop_back();
            k--;
        }

        int i = 0;
        while (i < stt.size() && stt[i] == '0') {
            i++;
        }

        string ans = "";
        for (int j = i; j < stt.size(); j++) {
            ans += stt[j];
        }

        return ans.empty() ? "0" : ans;
    }

    string removeKdigits(string num, int k) { return removeKdigits2(num, k); }
};