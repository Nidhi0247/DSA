class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }
        
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            vector<int> heights = matrix[i];
            sort(heights.begin(), heights.end(), greater<int>());
            
            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, heights[j] * (j + 1));
            }
        }
        
        return maxArea;
    }
};