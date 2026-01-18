class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c, int k) {
        int target = 0;
        for (int j = c; j < c + k; j++) target += grid[r][j]; 
        for (int i = r; i < r + k; i++) {
            int sum = 0;
            for (int j = c; j < c + k; j++) sum += grid[i][j];
            if (sum != target) return false;
        }
        for (int j = c; j < c + k; j++) {
            int sum = 0;
            for (int i = r; i < r + k; i++) sum += grid[i][j];
            if (sum != target) return false;
        }
        int diag1 = 0;
        for (int i = 0; i < k; i++)
         diag1 += grid[r + i][c + i];
        if (diag1 != target) return false;
        int diag2 = 0;
        for (int i = 0; i < k; i++) diag2 += grid[r + i][c + k - 1 - i];
        if (diag2 != target) return false;

        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int k = min(m, n); k >= 1; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    if (isMagic(grid, i, j, k)) return k;
                }
            }
        }
        return 1; 
    }
};