class Solution {
public:
    int longestPalindrome(string s) {
        // As we know , Ascii of alphabets can be upto 122
        // So we declared a hashmap of constant size (122) for safer side
        vector<int> hashmap(122, 0);

        for (auto v : s) {
            if (v >= 'A' && v <= 'Z')
                hashmap[v - 'A']++;
            else {

                // since , the Letters are case sensitive
                hashmap[v - '0']++; // here ascii of '0'=48
            }
        }

        int cnt = 0;
        int singles = 0;
        for (auto v : hashmap) {

            if (v != 0) {
                // if char occured at even number of times
                if (v % 2 == 0)
                    cnt += v;
                // occured odd number of times or single time
                else {
                    cnt += (v - 1);
                    singles++;
                }
            }
        }
        cout << cnt << endl << singles << endl;
        if (singles > 0)
            cnt += 1;
        return cnt;

        // unordered_map<char, int> mp;

        // for (auto v : s) {
        //     mp[v]++;
        // }

        // int cnt = 0;
        // int singles = 0;
        // for (auto v : mp) {
        //     int x = v.second;
        //     // if char occured at even number of times
        //     if (x % 2 == 0)
        //         cnt += x;
        //     // occured odd number of times or single time
        //     else {
        //         cnt += (x - 1);
        //         singles++;
        //     }
        // }
        // if (singles > 0)
        //     cnt += 1;
        // return cnt;
    }
};