class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //APPROACH 1 : TC: O(n) , SC: O(n)
        stack<pair<int, char>> st;

        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                if (s[i] == '(' || s[i] == ')') {
                    st.push({i, s[i]});
                }

            } else {

                if (s[i] == '(' || s[i] == ')') {
                    pair<int, char> p = st.top();
                    if (p.second == '(' && s[i] == ')') {
                        st.pop();
                    } else {
                        st.push({i, s[i]});
                    }
                }
            }
        }
        unordered_map<int, int> mp;
        while (!st.empty()) {
            pair<int, char> p = st.top();
            mp[p.first] = 1;
            st.pop();
        }
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(i) == mp.end()) {
                ans += s[i];
            }
        }
        return ans;
    }
};