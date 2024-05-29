class Solution {
public:
    //  int solve(string &s)
    //  {
    //      int n=s.size();
    //      long long sum=0;
    //      for(int i=0;i<n;i++)
    //      {
    //          int rightbit=s[n-1-i]-'0';
    //          sum = sum + static_cast<long long>(rightbit) * (1LL << i);
    //      }
    //      return sum;
    //  }

    int numStep(string& s) {
        int cnt = 0;
        string num = s;
        while (num != "1") {
            if (num.back() == '0') {

                num.pop_back();
            } else {
                int i = num.size() - 1;
                while (i >= 0 && num[i] == '1') {
                    num[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    num[i] = '1';
                } else {
                    num.insert(num.begin(), '1');
                }
            }
            cnt++;
        }
        return cnt;
    }

    int numSteps(string s) { return numStep(s); }
};