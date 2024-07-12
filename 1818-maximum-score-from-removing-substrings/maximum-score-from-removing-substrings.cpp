class Solution {
public:
    int solve(string s, int x, int y) {
        auto [substrs, points] = chooseSubstringsAndScores(x, y);
        int totalScore = 0;
        string tempStr = s;

        for (int pass = 0; pass < 2; ++pass) {
            totalScore +=
                processSubstrings(tempStr, substrs[pass], points[pass]);
        }

        return totalScore;
    }

    pair<vector<string>, vector<int>> chooseSubstringsAndScores(int x, int y) {
        if (y > x) {
            return {{"ba", "ab"}, {y, x}};
        } else {
            return {{"ab", "ba"}, {x, y}};
        }
    }

    int processSubstrings(string& s, const string& substr, int points) {
        int score = 0;
        string tempStack;

        for (char ch : s) {
            if (!tempStack.empty() && tempStack.back() == substr[0] &&
                ch == substr[1]) {
                score += points;
                tempStack.pop_back();
            } else {
                tempStack.push_back(ch);
            }
        }

        s = tempStack;
        return score;
    }

    int maximumGain(string s, int x, int y) { return solve(s, x, y); }

    // int solve1(string& s, int x, int y) {
    //     stack<char> st;
    //     st.push('1');
    //     int sum = 0;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (st.top() == 'a' && s[i] == 'b') {

    //             st.pop();
    //             sum += x;
    //         } else {
    //             st.push(s[i]);
    //         }
    //     }

    //     while (st.size() > 1) {
    //         char front1 = st.top();
    //         st.pop();
    //         char front2 = st.top();
    //         if (front1 == 'a' && front2 == 'b') {
    //             sum += y;
    //         }
    //     }
    //     return sum;
    // }

    // int solve2(string& s, int x, int y) {
    //     stack<char> st;
    //     st.push('1');
    //     int sum = 0;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (st.top() == 'b' && s[i] == 'a') {

    //             st.pop();
    //             sum += y;
    //         } else {
    //             st.push(s[i]);
    //         }
    //     }

    //     while (st.size() > 1) {
    //         char front1 = st.top();
    //         st.pop();
    //         char front2 = st.top();
    //         if (front1 == 'b' && front2 == 'a') {
    //             sum += x;
    //         }
    //     }
    //     return sum;
    // }
    // int maximumGain(string s, int x, int y) {
    //     int ans = -1;
    //     if (x > y) {
    //         ans = solve1(s, x, y);
    //     }
    //     if (x <= y) {
    //         ans = solve2(s, x, y);
    //     }

    //     return ans;
    // }
};