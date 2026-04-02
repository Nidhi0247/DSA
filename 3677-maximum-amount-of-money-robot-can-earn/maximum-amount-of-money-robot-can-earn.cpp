class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN/2)));
        
        // Initialize
        for (int k = 0; k <= 2; k++) {
            if (coins[0][0] >= 0) dp[0][0][k] = coins[0][0];
            else dp[0][0][k] = (k > 0 ? 0 : coins[0][0]);
        }
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                for (int k = 0; k <= 2; k++) {
                    if (r == 0 && c == 0) continue;
                    int gain = coins[r][c];
                    
                    // From top
                    if (r > 0) dp[r][c][k] = max(dp[r][c][k], dp[r-1][c][k] + (gain >= 0 ? gain : gain));
                    // From left
                    if (c > 0) dp[r][c][k] = max(dp[r][c][k], dp[r][c-1][k] + (gain >= 0 ? gain : gain));
                    
                    // Neutralize robber if negative and k>0
                    if (gain < 0 && k > 0) {
                        if (r > 0) dp[r][c][k] = max(dp[r][c][k], dp[r-1][c][k-1]);
                        if (c > 0) dp[r][c][k] = max(dp[r][c][k], dp[r][c-1][k-1]);
                    }
                }
            }
        }
        
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};