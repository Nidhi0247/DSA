class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<int>> dp(3, vector<int>(m, INT_MIN / 2)); // neutralize remain / col num
        dp[2][0] = 0;
        dp[1][0] = 0;
        dp[0][0] = 0;
        int temp;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                for (int k = 2; k >= 0; k--){
                    temp = dp[k][j] + coins[i][j];
                    if (k > 0 && coins[i][j] < 0){
                        temp = max(temp, dp[k - 1][j]);
                    }
                    if (j > 0){
                        temp = max(temp, dp[k][j - 1] + coins[i][j]);
                        if (k > 0 && coins[i][j] < 0){
                            temp = max(temp, dp[k - 1][j - 1]);
                        }
                    }
                    dp[k][j] = temp;
                }
            }
        }
        return max(max(dp[0][m - 1], dp[1][m - 1]), dp[2][m - 1]);
    }
};