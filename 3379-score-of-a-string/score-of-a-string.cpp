class Solution {
public:
    int scoreOfString(string s) {
        int sc=0;
        
        for(int i=1;i<s.size();i++)
        {
            sc+=abs(s[i]-s[i-1]);
        }
        return sc;
    }
};