class Solution {
public:
    vector<string> L20 = {"",        "One",       "Two",      "Three",
                          "Four",    "Five",      "Six",      "Seven",
                          "Eight",   "Nine",      "Ten",      "Eleven",
                          "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                          "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> TNS = {"",      "",      "Twenty",  "Thirty", "Forty",
                          "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> THS = {"", "Thousand", "Million", "Billion"};

public:
    string solve(int n) {
        if (n == 0)
            return "Zero";

        int i = 0;
        string wds;

        while (n > 0) {
            if (n % 1000 != 0) {
                wds = hlp(n % 1000) + THS[i] + " " + wds;
            }
            n /= 1000;
            i++;
        }

        while (!wds.empty() && wds.back() == ' ') {
            wds.pop_back();
        }

        return wds;
    }
    string hlp(int n) {
        if (n == 0) {
            return "";
        } else if (n < 20) {
            return L20[n] + " ";
        } else if (n < 100) {
            return TNS[n / 10] + " " + hlp(n % 10);
        } else {
            return L20[n / 100] + " Hundred " + hlp(n % 100);
        }
    }
    string numberToWords(int num) { return solve(num); }
};