class Solution {
public:
    vector<pair<int, int>> createJobPairs(const vector<int>& jp,
                                          const vector<int>& jd) {
        vector<pair<int, int>> jpairs;
        for (int i = 0; i < jd.size(); i++) {
            jpairs.push_back(make_pair(jp[i], jd[i]));
        }
        return jpairs;
    }

    void sortJobsAndWorkers(vector<pair<int, int>>& jpairs, vector<int>& wkrs) {
        sort(jpairs.begin(), jpairs.end());
        sort(wkrs.begin(), wkrs.end());
    }

    int calcTotalProfit(vector<pair<int, int>>& jpairs, vector<int>& wkrs) {
        int jidx = jpairs.size() - 1;
        int pidx = jpairs.size() - 1;
        int widx = wkrs.size() - 1;

        int tprofit = 0;

        while (widx >= 0 && jidx >= 0) {
            if (wkrs[widx] >= jpairs[jidx].second) {
                widx--;
                tprofit += jpairs[jidx].first;
                jidx = pidx;
            } else {
                jidx--;
            }
        }

        return tprofit;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> jpairs = createJobPairs(profit, difficulty);
        sortJobsAndWorkers(jpairs, worker);
        return calcTotalProfit(jpairs, worker);
    }
};