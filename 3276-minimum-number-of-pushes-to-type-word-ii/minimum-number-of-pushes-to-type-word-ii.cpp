class Solution {
public:
    int solve(string& word) {
        unordered_map<char, int> charFrequency;
        for (char c : word) {
            charFrequency[c]++;
        }

        vector<int> frequencyList;
        for (const auto& entry : charFrequency) {
            frequencyList.push_back(entry.second);
        }

        sort(frequencyList.rbegin(), frequencyList.rend());

        int totalPushes = 0;
        for (int i = 0; i < frequencyList.size(); ++i) {
            totalPushes += frequencyList[i] * ((i / 8) + 1);
        }

        return totalPushes;
    }
    int minimumPushes(string word) { return solve(word); }
};