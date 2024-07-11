class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int x = st.top() + 1;
                int y = i;
                reverse(s.begin() + x, s.begin() + y);
                st.pop();
            }
        }
        string res = "";
        for (auto v : s) {
            if (v != '(' && v != ')')
                res += v;
        }
        return res;
    }
};