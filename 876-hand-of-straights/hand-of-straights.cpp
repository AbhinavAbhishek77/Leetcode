class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        int m = groupSize;

        if (n % m != 0)
            return false;
        sort(hand.begin(), hand.end());

        map<int, int> mp;
        for (auto v : hand) {
            mp[v]++;
        }

        while(!mp.empty()) {

            // int curr = v.first;

            int curr = mp.begin()->first;

            for (int i = 0; i < m; i++) {
                if (mp[curr + i] == 0) {
                    return false;
                }
                mp[curr + i]--;

                if (mp[curr + i] == 0) {
                    mp.erase(curr + i);
                }
            }
        }

        return true;
    }
};