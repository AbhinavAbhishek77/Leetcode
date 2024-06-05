class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        vector<int> hash(26, 0);
        int mini = INT_MAX;
        int c = 0;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            c++;
            for (auto v : words) {
                int cnt = count(v.begin(), v.end(), ch);
                // cout<<cnt<< " ";
                mini = min(mini, cnt);
                // cout<<mini<<" ";
            }
            // cout<<ch-'a'<<" ";
            hash[ch - 'a'] += mini;
            mini = INT_MAX;
            // cout<<hash[ch - 'a']<<" ";
        }

        // for(auto v:hash) cout<<v<<" ";
        // cout<<c<<endl;
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            char ch = i + 'a';
            // cout<<ch<<" ";
            string str = string(1, ch);
            // cout<<str<<" ";
            int cnt1 = hash[i];
            // cout<<cnt1<<" ";
            for (int i = 0; i < cnt1; i++) {
                ans.push_back(str);
                // cout<<str<<" ";
            }
        }
        return ans;
    }
};