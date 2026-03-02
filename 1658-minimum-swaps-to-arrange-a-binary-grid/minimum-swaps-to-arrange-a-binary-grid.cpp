class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros(n);
 
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) count++;
            trailingZeros[i] = count;
        }   
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int needed = n - i - 1;
            int j = i;
            while (j < n && trailingZeros[j] < needed) j++;
            if (j == n) return -1;
            swaps += j - i;
            while (j > i) {
                swap(trailingZeros[j], trailingZeros[j - 1]);
                j--;
            }
        }
        return swaps;
    }
};