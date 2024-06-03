class Solution {
public:
    int appendCharacters(string s, string t) {
        // // doesnt exist or exist in back
        // unordered_map<char, int> mp;
        // int maxi = -1;

        // for (int i = 0; i < s.size(); i++) {
        //     if (mp.find(s[i]) == mp.end())
        //         mp[s[i]] = i;
        // }
        // int i = 0;
        // for (i = 0; i < t.size(); i++) {
        //     if (maxi == -1) {
        //         if (mp.find(t[i]) != mp.end()) {

        //             maxi = max(mp[t[i]], maxi);
        //             cout << maxi << " ";
        //         } else
        //             break;

        //     } else {
        //         // exist
        //         if (mp.find(t[i]) != mp.end()) {
        //             // ahead
        //             if (mp[t[i]] > maxi) {
        //                 maxi = max(maxi, mp[t[i]]);
        //                 //   cout<<maxi<<" ";
        //             }
        //             // exist before
        //             else {
        //                 break;
        //             }
        //         }
        //         // doent exist
        //         else {
        //             // cout<<i;
        //             break;
        //         }
        //     }
        // }

        // if (i != t.size()) {
        //     return t.size() - i;
        // } else
        //     return 0;

        int a = s.size(), b = t.size();
        int i = 0, j = 0;

        while (i < a && j < b) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }

        // If j is less than the length of t, it means we haven't matched
        // all characters in t
        return b - j;
    }
};