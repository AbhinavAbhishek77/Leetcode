class Solution {
public:
    // TC==>O(n)
    // SC==>O(26)
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        vector<int> a(256, -1);
        vector<int> b(256, -1);
        for (int i = 0; i < s.size(); ++i) 
        {
            if (a[s[i]] == -1 && b[t[i]] == -1) 
            {
                a[s[i]] = t[i];
                b[t[i]] = s[i];
            } 
            
            else if (a[s[i]] != t[i] || b[t[i]] != s[i])
             {
                return false;
            }
        }
        return true;
    }
};