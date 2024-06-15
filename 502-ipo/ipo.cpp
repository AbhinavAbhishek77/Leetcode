class Solution {
public:
    int mcap(int numProjects, int initialCapital, vector<int>& projectProfits,
             vector<int>& projectCapital) {
        priority_queue<pair<int, int>> maxProfitQueue;
        int currentCapital = initialCapital;
        int projectIndex = 0;
        vector<pair<int, int>> projects;

        for (int i = 0; i < projectProfits.size(); ++i) {
            projects.push_back(make_pair(projectCapital[i], projectProfits[i]));
        }
        sort(projects.begin(), projects.end());
        while (numProjects > 0) {
            bool projectAdded = false;
            while (projectIndex < projects.size() &&
                   projects[projectIndex].first <= currentCapital) {
                maxProfitQueue.push(make_pair(
                    projects[projectIndex].second,
                    projects[projectIndex]
                        .first)); 
                projectAdded = true;
                ++projectIndex;
            }
            if (!maxProfitQueue.empty()) {
                auto [profit, capital] = maxProfitQueue.top();
                maxProfitQueue.pop();
                projectAdded = true;
                currentCapital +=
                    profit; 
                --numProjects;
            }
            if (!projectAdded) {
                break;
            }
        }

        return currentCapital;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        return mcap(k, w, profits, capital);
    }
};