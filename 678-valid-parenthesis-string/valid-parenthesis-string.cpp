class Solution {
public:
    void processString(string inputStr, int& minOpen, int& maxOpen) {
        for (char ch : inputStr) {
            minOpen += (ch == '(') ? 1 : -1;
            maxOpen += (ch != ')') ? 1 : -1;
            if (maxOpen < 0)
                return;
            minOpen = max(minOpen, 0);
        }
    }
    bool solve(string inputStr) {
        int minOpen = 0, maxOpen = 0;
        processString(inputStr, minOpen, maxOpen);
        return minOpen == 0;
    }
    bool checkValidString(string s) { return solve(s); }
};