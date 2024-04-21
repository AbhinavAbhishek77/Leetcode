class Solution {
public:
 bool isValidPath(int nodes, vector<vector<int>>& edges, int start, int end) {
        if (start == end) {
            return true;
        }
        
        unordered_map<int, vector<int>> adjList;
        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjList[from] = adjList.find(from) != adjList.end() ? adjList[from] : vector<int>();
            adjList[from].push_back(to);
            adjList[to] = adjList.find(to) != adjList.end() ? adjList[to] : vector<int>();
            adjList[to].push_back(from);
        }
        
        unordered_set<int> visitedNodes;
        visitedNodes.insert(start);
        return depthFirstSearch(adjList, start, end, visitedNodes);
    }

    bool depthFirstSearch(unordered_map<int, vector<int>>& adjList, int key, int destination, unordered_set<int>& visitedNodes) {
        if (find(adjList[key].begin(), adjList[key].end(), destination) != adjList[key].end()) {
            return true;
        }

        for (int nextKey : adjList[key]) {
            if (visitedNodes.find(nextKey) == visitedNodes.end()) {
                visitedNodes.insert(nextKey);
                if (depthFirstSearch(adjList, nextKey, destination, visitedNodes)) {
                    return true;
                }
            }
        }
        
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) 
    {
return isValidPath(n, edges, source, destination);




    }
};