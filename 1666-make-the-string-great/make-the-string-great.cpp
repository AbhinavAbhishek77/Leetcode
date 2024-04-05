class Solution {
public:
//TC==>O(n)
//SC==>O(n)
    string makeGood(string s) {
        stack<char> st;
        for (int i = s.size() - 1; i >= 0; i--) {
            st.push(s[i]);
        }

        stack<char> at;
        while (st.size() > 1) {
            char c1 = st.top();
            st.pop();
            char c2 = st.top();
            st.pop();

            if (abs(c1 - c2) == 32 ) {
                if (!at.empty()) {
                    st.push(at.top());
                    at.pop();
                }
            } else {
                at.push(c1);
                st.push(c2);
            }
        }

        string ans = "";
        while (!at.empty()) {
            ans += at.top();
            at.pop();
        }

        reverse(ans.begin(), ans.end());

        if (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }


//APPROACH: 2
    //     string makeGood(string s) {
    //     stack<char> st;

    //     for (auto v : s) {
    //         if (!st.empty() && abs(v - st.top()) == 32) {
    //             st.pop(); // Remove the top element if it cancels with the
    //             current element
    //         } else {
    //             st.push(v);
    //         }
    //     }

    //     string ans = "";
    //     while (!st.empty()) {
    //         ans += st.top();
    //         st.pop();
    //     }

    //     reverse(ans.begin(), ans.end());

    //     return ans;
    // }
};