class Solution {
public:
    int findMaximalRectangle(vector<vector<char>>& inputMatrix)
     {
        int rows = inputMatrix.size(), cols = inputMatrix[0].size(),
            maxArea = 0;
        vector<int> heights(cols, 0);
        for (int i = 0; i < rows; i++) 
        {
            calculateHeights(inputMatrix[i], heights);
            maxArea = calculateMaxRectangleArea(heights, maxArea);
        }
        return maxArea;
    }
    void calculateHeights(vector<char>& row, vector<int>& heights) 
    {
        for (int j = 0; j < row.size(); j++)
            heights[j] = (row[j] == '0') ? 0 : heights[j] + 1;
    }
    int calculateMaxRectangleArea(vector<int>& heights, int maxArea)
     {
        for (int j = 0; j < heights.size(); j++) 
        {
            int width = 0, length = heights[j];
            for (int w = 0; j - w >= 0 && heights[j - w]; w++) 
            {
                length = min(length, heights[j - w]);
                maxArea = max(maxArea, length * (w + 1));
            }
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        return findMaximalRectangle(matrix);
    }
};