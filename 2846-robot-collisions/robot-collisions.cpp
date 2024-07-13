class Solution {
public:
    vector<int> solve(vector<int>& robotPositions, vector<int>& robotHealths,
                      string robotDirections) {
        auto combinedData =
            combineData(robotPositions, robotHealths, robotDirections);
        sort(combinedData.begin(), combinedData.end());

        combinedData = resolveCollisions(combinedData);

        return getResult(combinedData, robotPositions);
    }

    vector<tuple<int, char, int>> combineData(const vector<int>& robotPositions,
                                              const vector<int>& robotHealths,
                                              const string& robotDirections) {
        vector<tuple<int, char, int>> combinedData;
        for (size_t i = 0; i < robotPositions.size(); ++i) {
            combinedData.emplace_back(robotPositions[i], robotDirections[i],
                                      robotHealths[i]);
        }
        return combinedData;
    }

    vector<tuple<int, char, int>>
    resolveCollisions(vector<tuple<int, char, int>>& combinedData) {
        bool hasCollision = true;
        while (hasCollision) {
            vector<tuple<int, char, int>> stack;
            hasCollision = false;
            for (auto& [position, direction, health] : combinedData) {
                while (!stack.empty() && direction == 'L' &&
                       get<1>(stack.back()) == 'R') {
                    hasCollision = true;
                    auto [prevPosition, prevDirection, prevHealth] =
                        stack.back();
                    stack.pop_back();
                    if (health == prevHealth) {
                        health = 0;
                        break;
                    } else if (health > prevHealth) {
                        health -= 1;
                    } else {
                        health = 0;
                        prevHealth -= 1;
                        stack.emplace_back(prevPosition, prevDirection,
                                           prevHealth);
                        break;
                    }
                }
                if (health > 0) {
                    stack.emplace_back(position, direction, health);
                }
            }
            combinedData = move(stack);
        }
        return combinedData;
    }

    vector<int> getResult(const vector<tuple<int, char, int>>& combinedData,
                          const vector<int>& robotPositions) {
        unordered_map<int, int> positionIndexMap;
        for (size_t i = 0; i < robotPositions.size(); ++i) {
            positionIndexMap[robotPositions[i]] = i;
        }

        vector<tuple<int, char, int>> sortedData = combinedData;
        sort(sortedData.begin(), sortedData.end(),
             [&](const auto& a, const auto& b) {
                 return positionIndexMap[get<0>(a)] <
                        positionIndexMap[get<0>(b)];
             });

        vector<int> result;
        for (const auto& [position, direction, health] : sortedData) {
            result.push_back(health);
        }

        return result;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        return solve(positions, healths, directions);
    }
};