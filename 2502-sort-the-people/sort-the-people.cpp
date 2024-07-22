class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> ans(names.size());
        for (int i = 0; i < names.size(); i++) {
            ans[i] = {heights[i], names[i]};
        }

        sort(ans.rbegin(), ans.rend());

        vector<string> res;
        for (int i = 0; i < ans.size(); i++) {
            res.push_back(ans[i].second);
        }
        return res;
    }
};